#include "adminform.h"
#include "ui_adminform.h"

AdminForm::AdminForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminForm)
{
    ui->setupUi(this);
    /*********************修改老师信息*************************************************************************************************************/
    connect(ui->FindButton,&QPushButton::clicked,[=]{
        QString id = ui->idText->text();
        QString name = ui->nameText->text();
        QString subject = ui->subjectText->text();
        QString classNum = ui->classText->text();
        int sex = ui->sexBox->currentIndex();

        bool idEmpty = false;
        bool nameEmpty = false;
        bool subjectEmpty = false;
        bool classEmpty = false;
        bool sexEmpty = false;

        if(QString::compare(id,"")==0)//判断空输入
            idEmpty = true;
        if(QString::compare(name,"")==0)//判断空输入
            nameEmpty = true;
        if(QString::compare(subject,"")==0)//判断空输入
            subjectEmpty = true;
        if(QString::compare(classNum,"")==0)//判断空输入
            classEmpty = true;
        if(sex == 0){                       //判断空输入并处理性别数据
            sexEmpty = true;
            sex = 3;
        }
        else
            --sex;

        QString userSentence;
        QString relationSentence;
        if(!idEmpty){
            if(!nameEmpty || !subjectEmpty || !classEmpty){
                QMessageBox::about(this,"查询冲突","工号是单独查询条件");
                return;
            }
            userSentence.append("id = "+id);
            relationSentence.append("id = "+id);
        }
        if(!nameEmpty){
            if(!idEmpty || !subjectEmpty || !classEmpty){
                QMessageBox::about(this,"查询冲突","性名是单独查询条件");
                return;
            }
            userSentence.append("name = '"+name+"'");
        }
        if(!subjectEmpty){
            if(!idEmpty || !nameEmpty){
                QMessageBox::about(this,"查询冲突","学科是筛选查询条件，无法对工号或用户名进行筛选");
                return;
            }
            userSentence.append(",subject = '"+subject+"'");
        }
        if(!sexEmpty){
            if(!idEmpty || !nameEmpty){
                QMessageBox::about(this,"查询冲突","性别是筛选查询条件，无法对工号或用户名进行筛选");
                return;
            }
            userSentence.append(",sex = "+QString::number(sex));
        }
        if(!classEmpty){
            if(!idEmpty || !nameEmpty){
                QMessageBox::about(this,"查询冲突","班级是筛选查询条件，无法对工号或用户名进行筛选");
                return;
            }
            relationSentence.append("class = "+classNum);
        }

        if(userSentence.startsWith(","))
            userSentence = userSentence.right(userSentence.length()-1);

        qDebug()<<userSentence;

        if(!(QString::compare(userSentence,"")==0)){
            QSqlTableModel *infoTableModel = new QSqlTableModel(this);
            infoTableModel->setTable("teacher");
            infoTableModel->setFilter(userSentence);
            infoTableModel->select();
            int teacherNum = infoTableModel->rowCount();//符合条件的老师个数
            if(teacherNum==0){
                QMessageBox::about(this,"查询失败","无此老师");
                return;
            }
            ui->infoTable->setModel(infoTableModel);
            //生成对应的relationSentence查询语句（在原有的语句上append）
            QString tempSentence = "";
            for (int i=0;i<teacherNum;++i) {
                QSqlRecord record = infoTableModel->record(i);
                tempSentence.append(" or id = "+record.value("id").toString());
            }
            if(tempSentence.startsWith(" or"))
                tempSentence = tempSentence.right(tempSentence.length()-3);
            if(!(relationSentence==""))
                relationSentence.append(" and "+tempSentence);
            qDebug()<<tempSentence;
            qDebug()<<relationSentence;
            //开始执教关系查询
            QSqlTableModel *relationTableModel = new QSqlTableModel(this);
            relationTableModel->setTable("relation");
            relationTableModel->setFilter(relationSentence);
            relationTableModel->select();
            if(relationTableModel->rowCount()==0){
                QMessageBox::about(this,"查询失败","无此信息");
                return;
            }
            ui->relationTable->setModel(relationTableModel);
        }
        else {
            //处理按班级检索
            QSqlTableModel *relationTableModel = new QSqlTableModel(this);
            relationTableModel->setTable("relation");
            relationTableModel->setFilter(relationSentence);
            relationTableModel->select();
            int teacherNum = relationTableModel->rowCount();
            if(teacherNum==0){
                QMessageBox::about(this,"查询失败","无此班级");
                return;
            }
            //生成对应的userSentence查询语句（在原有的语句上append）
            QString tempSentence = "";
            for (int i = 0; i<teacherNum; i++) {
                QSqlRecord record = relationTableModel->record(i);
                tempSentence.append(" or id = "+record.value("id").toString());
            }
            if(tempSentence.startsWith(" or"))
                tempSentence = tempSentence.right(tempSentence.length()-3);
            userSentence.append(tempSentence);
            qDebug()<<userSentence;
            //开始教师信息查询
            QSqlTableModel *infoTableModel = new QSqlTableModel(this);
            infoTableModel->setTable("teacher");
            infoTableModel->setFilter(userSentence);
            infoTableModel->select();
//            relationSentence = "";//清空relationSentence，重新生成
//            for (int i = 0; i<infoTableModel->rowCount(); i++) {
//                QSqlRecord record = infoTableModel->record(i);
//                relationSentence.append(" or id = "+record.value("id").toString());
//            }
//            if(tempSentence.startsWith(" or"))
//                tempSentence = tempSentence.right(tempSentence.length()-3);
//            qDebug()<<relationSentence;
//            //刷新执教关系表
//            relationTableModel->setFilter(relationSentence);
//            relationTableModel->select();
//            //教师对应relation查询
//            infoTableModel->setTable("relation");
//            infoTableModel->setFilter(userSentence);
//            infoTableModel->select();
            ui->infoTable->setModel(infoTableModel);
            ui->relationTable->setModel(relationTableModel);
        }



    });

    connect(ui->AddButton,&QPushButton::clicked,[=]{
        QString id = ui->idText->text();
        QString name = ui->nameText->text();
        QString subject = ui->subjectText->text();
        QString classNum = ui->classText->text();
        int sex = ui->sexBox->currentIndex();

        bool idEmpty = false;
        bool nameEmpty = false;
        bool subjectEmpty = false;
        bool classEmpty = false;
        bool sexEmpty = false;

        bool addInfo = false;
        bool addRelation = false;

        if(QString::compare(id,"")==0)//判断空输入
            idEmpty = true;
        if(QString::compare(name,"")==0)//判断空输入
            nameEmpty = true;
        if(QString::compare(subject,"")==0)//判断空输入
            subjectEmpty = true;
        if(QString::compare(classNum,"")==0)//判断空输入
            classEmpty = true;
        if(sex == 0){                       //判断空输入并处理性别数据
            sexEmpty = true;
            sex = 3;
        }
        else
            --sex;

        //处理添加老师的空输入
        if((idEmpty||nameEmpty||subjectEmpty)&&classEmpty){
            QString warnSentence = "";
            if(idEmpty)
                warnSentence.append("工号");
            if(nameEmpty)
                warnSentence.append("、姓名");
            if(subjectEmpty)
                warnSentence.append("、科目");
            if(sexEmpty)
                warnSentence.append("、性别");
            if(warnSentence.startsWith("、"))
                warnSentence = warnSentence.right(warnSentence.length()-1);
            QMessageBox::warning(this,"输入错误",warnSentence+"未填写,新增教师请输入完整信息");
            return ;
        }
        //处理全空输入
        if(idEmpty||nameEmpty||subjectEmpty||classEmpty){
            QMessageBox::warning(this,"输入错误","未填写信息");
            return ;
        }
        //处理添加执教关系输入
//        if(!classEmpty){
//            if(id)
//        }

        if(classEmpty)
            addInfo = true;
        else
            addRelation = true;

        QString userSentence = "";
        QString relationSentence = "";

        if (addInfo) {
            //开始添加
            QSqlQuery query;
            QString querySentense = "insert into teacher(id,name,sex,subject) "
                                    "values("+id+",'"+name+"',"+QString::number(sex)+",'"+subject+"')";
            if(!query.exec("insert into user values ("+id+",'"+name+"',1,'123456'")){
                QMessageBox::critical(nullptr, QObject::tr("数据库冲突、请检查数据"),
                                      query.lastError().text());
                return;
            }
            if(!query.exec(querySentense)){
                QMessageBox::critical(nullptr, QObject::tr("数据库冲突、请检查数据"),
                                      query.lastError().text());
                return;
            }
            //查询添加结果
            QSqlTableModel *tableModel = new QSqlTableModel(this);
            tableModel->setTable("teacher");
            tableModel->setFilter("id = "+id);
            tableModel->select();
            ui->infoTable->setModel(tableModel);
        }

        if(addRelation){
            //开始按条件筛选老师
            QSqlTableModel *tableModel = new QSqlTableModel(this);
            tableModel->setTable("teacher");
            tableModel->setFilter("id = "+id);
            tableModel->select();
            ui->infoTable->setModel(tableModel);
        }

    });

    /*********************修改学生信息********************************************************************************************************/
    //学生名字or学号查询
    connect(ui->FindButton_2,&QPushButton::clicked,[=]{
        QString id = ui->idText_2->text();
        QString name = ui->nameText_2->text();
        bool idEmpty = false;
        bool nameEmpty = false;

        if(QString::compare(id,"")==0)//判断空输入
            idEmpty = true;
        if(QString::compare(name,"")==0)//判断空输入
            nameEmpty = true;

        if(idEmpty == true && nameEmpty == true){
            //排除空输入
            QMessageBox::critical(nullptr, QObject::tr("输入错误"), "请输入学生姓名或学号");
            return;
        }
        else if(idEmpty == false && nameEmpty == true){
            //只输入学号
            QSqlTableModel *tableModel = new QSqlTableModel(this);
            tableModel->setTable("info");
            tableModel->setFilter("id = "+id);
            tableModel->select();
            if(tableModel->rowCount()==0){
                QMessageBox::about(this,"查询失败","无此学号");
                return;
            }
            tableModel->select();
            ui->infoTable_2->setModel(tableModel);
        }
        else if (idEmpty == true && nameEmpty == false) {
            //只输入姓名
            QSqlTableModel *tableModel = new QSqlTableModel(this);
            tableModel->setTable("info");
            tableModel->setFilter("name = "+name);
            tableModel->select();
            if(tableModel->rowCount()==0){
                QMessageBox::about(this,"查询失败","无此学生");
                return;
            }
            tableModel->select();
            ui->infoTable_2->setModel(tableModel);
        }
        else if (idEmpty == false && nameEmpty == false) {
            //输入学号姓名
            QSqlTableModel *tableModel = new QSqlTableModel(this);
            tableModel->setTable("info");
            tableModel->setFilter("name = "+name+"and id = "+id);
            tableModel->select();
            if(tableModel->rowCount()==0){
                QMessageBox::about(this,"查询失败","无此学生");
                return;
            }
            tableModel->select();
            ui->infoTable_2->setModel(tableModel);
        }
        //清空输入
        ui->idText_2->setText("");
        ui->nameText_2->setText("");
    });

    //学生名字or学号添加
    connect(ui->AddButton_2,&QPushButton::clicked,[=]{
        QString id = ui->idText_2->text();
        QString name = ui->nameText_2->text();
        bool idEmpty = false;
        bool nameEmpty = false;

        if(QString::compare(id,"")==0)//判断空输入
            idEmpty = true;
        if(QString::compare(name,"")==0)//判断空输入
            nameEmpty = true;

        if(idEmpty == true && nameEmpty == true){
            //排除空输入
            QMessageBox::critical(nullptr, QObject::tr("输入错误"), "请输入要添加学生的姓名和学号");
            return;
        }
        else if(idEmpty == false && nameEmpty == true){
            //只输入学号
            QMessageBox::critical(nullptr, QObject::tr("输入错误"), "请输入要添加学生的姓名");
            return;
        }
        else if (idEmpty == true && nameEmpty == false) {
            //只输入姓名
            QMessageBox::critical(nullptr, QObject::tr("输入错误"), "请输入要添加学生的学号");
            return;
        }
        else if (idEmpty == false && nameEmpty == false) {
            //输入学号姓名
            //先判断学号是否存在
            QSqlTableModel *tableModel = new QSqlTableModel(this);
            tableModel->setTable("info");
            tableModel->setFilter("id = "+id);
            tableModel->select();
            if(tableModel->rowCount()!=0){
                QMessageBox::critical(this,"添加失败","此学号已存在");
                ui->infoTable_2->setModel(tableModel);
                return;
            }
            //开始添加
            QSqlQuery query;
            if(!query.exec("insert into user values ("+id+",'"+name+"',2,'123456'")){
                QMessageBox::critical(nullptr, QObject::tr("数据库冲突、请检查数据"),
                                      query.lastError().text());
                return;
            }
            QString querySentense = "insert into info(id,name,class,sex,birth) "
                                    "values("+id+",'"+name+"',0,0,'请补充信息')";
            if(!query.exec(querySentense)){
                QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                                      query.lastError().text());
            }
            //显示结果
            tableModel->setTable("info");
            tableModel->setFilter("id = "+id);
            tableModel->select();
            ui->infoTable_2->setModel(tableModel);
        }
        //清空输入
        ui->idText_2->setText("");
        ui->nameText_2->setText("");
    });

    //按老师查询
    connect(ui->teacherText_2,&QLineEdit::editingFinished,[=]{
        QString teacher = ui->teacherText_2->text();
        if(QString::compare(teacher,"")==0)//排除空输入
            return;
        QList<QString> classes;
        QSqlQuery idQuery;
        QSqlQuery classQuery;
        QSqlTableModel *resultModel = new QSqlTableModel(this);
        //查找老师id
        QString querySentense = "select id from user "
                                "where name = '"+teacher+"'";
        if(!idQuery.exec(querySentense))
            QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                                  idQuery.lastError().text());
        idQuery.next();
        QString id = idQuery.value(0).toString();
        if(QString::compare(id,"")!=0){
            //查找老师所教班级，将班级压入链表
            classQuery.exec("select class from relation "
                            "where id =" + id);
            while (classQuery.next()) {
                classes << classQuery.value(0).toString();
            }
            //根据链表生成筛选语句
            QString filterSentense = "class = ";
            for (int i=0;i<(classes.size()-1);i++) {
                filterSentense.append(classes.at(i)+" or class = ");
            }
            filterSentense.append(classes.at(classes.size()-1));
            //筛选，打印
            resultModel->setTable("info");
            resultModel->setFilter(filterSentense);
            if (resultModel->select()) {
                ui->infoTable_2->setModel(resultModel);
            }
        } else {
            QMessageBox::about(this,"查询失败","老师名称输入错误或无此老师");
        }

        //清空输入
        ui->teacherText_2->setText("");
    });

    //按班级查询
    connect(ui->classText_2,&QLineEdit::editingFinished,[=]{
        QString classNum = ui->classText_2->text();

        if(QString::compare(classNum,"")==0)//排除空输入
            return;
        QSqlTableModel *model = new QSqlTableModel();
        model->setTable("info");
        model->setFilter("class = "+classNum);
        model->select();
        if(model->rowCount()==0)
            return ;
        ui->infoTable_2->setModel(model);

        //清空输入
        ui->classText_2->setText("");
    });

    /*********************高级修改模式*************************************************************************************************************/
    //刷新表按钮
    connect(ui->FreshButton,&QPushButton::clicked,[=]{
        QString tableName = ui->comboBox->currentText();

        EditableSqlModel *editableModel = new EditableSqlModel(tableName);
        QString query = "select * from " + tableName;
        editableModel->setQuery(query);

        ui->tableView->setModel(editableModel);
    });
    //执行按钮
    connect(ui->DoButtom,&QPushButton::clicked,[=]{
        QString sqlOrder = ui->SqlOrder->text();
        if(sqlOrder == "")
            return ;

        QSqlQuery query;
        if(!query.exec(sqlOrder))
            QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                                  query.lastError().text());

        QSqlQueryModel *queryModel = new QSqlQueryModel(this);
        queryModel->setQuery(query);

        ui->tableView->setModel(queryModel);
    });

}

AdminForm::~AdminForm()
{
    delete ui;
}

