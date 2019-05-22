#include "classteacherform.h"
#include "ui_classteacherform.h"

ClassTeacherForm::ClassTeacherForm(QString Name, int usergroup, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClassTeacherForm)
{
    ui->setupUi(this);

    if(usergroup == 1){
        ui->SubjectTeacherBox->setVisible(false);
    }else {
        ui->ClassTeacherBox->setVisible(false);
    }

    InitTeacherInfo(Name);

    InitClassInfo(teacherID);

    InitUiInfo();

    InfoChoose();

    ui->infoLabel->setText("欢迎回来，"+teacherName+"老师");

    connect(ui->ClassBox_1,&QComboBox::currentTextChanged,this,&ClassTeacherForm::InfoChoose);
    connect(ui->SexBox_1,&QComboBox::currentTextChanged,this,&ClassTeacherForm::InfoChoose);
    connect(ui->ChooseButton,&QPushButton::clicked,this,&ClassTeacherForm::ScoreChoose);
    connect(ui->AddButton_2,&QPushButton::clicked,this,&ClassTeacherForm::ScoreAdd);
    connect(ui->AddButton,&QPushButton::clicked,this,&ClassTeacherForm::StuAdd);
    connect(ui->DeleteButton,&QPushButton::clicked,this,&ClassTeacherForm::StuDel);
}

ClassTeacherForm::~ClassTeacherForm()
{
    delete ui;
}

void ClassTeacherForm::InitTeacherInfo(QString name)
{
    teacherName = name;
    //读取老师信息
    QSqlQuery query;
    if(!query.exec("select * from teacher "
                   "where name = '"+name+"'"))
        QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                              query.lastError().text());
    QSqlRecord record;
    while (query.next()) {
        record = query.record();
        teacherID = record.value("id").toInt();
        teacherSex = record.value("sex").toString();
        teacherSubject = record.value("subject").toString();
        qDebug()<<teacherID<<teacherSex<<teacherSubject;
    }

}

void ClassTeacherForm::InitClassInfo(int id)
{
    QSqlQuery query;
    QSqlRecord record;
    if(!query.exec("select class from relation "
                   "where id = "+QString::number(id)))
        QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                              query.lastError().text());
    while (query.next()) {
        record = query.record();
        classList.append(record.value("class").toInt());
        qDebug()<<classList.last();
    }
}

void ClassTeacherForm::InitUiInfo()
{
    QString className;
    ui->ClassBox_1->addItem("");
    ui->ClassBox_Score->addItem("");
    for (int i = 0; i < classList.length(); i++) {
        className = QString::number(classList.at(i));
        ui->ClassBox_1->addItem(className);
        ui->ClassBox_Score->addItem(className);
    }
}

void ClassTeacherForm::InfoChoose()
{
    QSqlTableModel *model = new QSqlTableModel(this);
    QString infoSentence = "";
    if(ui->ClassBox_1->currentText().isEmpty())
        for (int i=0; i<classList.length(); ++i) {
            infoSentence.append(" or class = "+QString::number(classList.at(i)));
        }
    else {
        infoSentence.append("class = "+ui->ClassBox_1->currentText());
    }
    if(!ui->SexBox_1->currentText().isEmpty()){
        int sex = ui->SexBox_1->currentIndex() - 1;
        infoSentence.append(" or sex = "+QString::number(sex));
    }
    if(infoSentence.startsWith(" or"))
        infoSentence = infoSentence.right(infoSentence.length()-3);
    model->setTable("info");
    model->setFilter(infoSentence);
    model->select();
    ui->tableView->setModel(model);
}

void ClassTeacherForm::ScoreAdd()
{
    QString testName = ui->AddTest->text();
    if(teacherSubject == "语文"){
        QSqlQuery query;
        QString querySentence = "alter table score_chinese add column "+testName;
        if(!query.exec(querySentence))
            QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                                  query.lastError().text());
    }else
    if(teacherSubject == "数学"){
        QSqlQuery query;
        QString querySentence = "alter table score_maths add column "+testName;
        if(!query.exec(querySentence))
            QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                                  query.lastError().text());
    }else
    if(teacherSubject == "英语"){
        QSqlQuery query;
        QString querySentence = "alter table score_english add column "+testName;
        if(!query.exec(querySentence))
            QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                                  query.lastError().text());
    }

}

void ClassTeacherForm::ScoreChoose()
{
    QString classNum = ui->ClassBox_Score->currentText();
    QString chooseNum = ui->ChooseLine->text();
    QString chooseMethod = ui->ChooseBox->currentText();
    QString chooseTest = ui->ChooseTest->text();
    bool classEmpty = false;
    bool chooseEmpty = false;
    bool methodEmpty = false;
    bool testEmpty = false;
    if(ui->ClassBox_Score->currentIndex()==0)
        classEmpty = true;
    if(ui->ChooseLine->text()=="")
        chooseEmpty = true;
    if(ui->ChooseBox->currentIndex()==0)
        methodEmpty = true;
    if(ui->ChooseTest->text()=="")
        testEmpty = true;



    QString idSentence = "";
    QString chooseSentence = "";
    QSqlTableModel idModel;
    QSqlRecord record;
    if(!classEmpty){
        idSentence.append("class = "+classNum);
    }else {
        for (int i=0; i<classList.length(); ++i) {
            idSentence.append(" or class = "+QString::number(classList.at(i)));
        }
        if(idSentence.startsWith(" or"))
            idSentence = idSentence.right(idSentence.length()-3);
    }

    idModel.setTable("info");
    idModel.setFilter(idSentence);
    idModel.select();

    idSentence = "";

    for (int i=0;i<idModel.rowCount();i++) {
        record = idModel.record(i);
        idSentence.append(" or id = "+record.value("id").toString());
    }
    if(idSentence.startsWith(" or"))
        idSentence = idSentence.right(idSentence.length()-3);

    if(!(chooseEmpty||methodEmpty)){
        if(idSentence!=""){
            if(!testEmpty)
                chooseSentence = "("+idSentence+") and "+chooseTest+chooseMethod+chooseNum;
            else
                chooseSentence = "("+idSentence+") and finalscore"+chooseMethod+chooseNum;
        }
    }else
        chooseSentence = idSentence;
    qDebug()<<chooseSentence;
    QSqlRelationalTableModel *model = new QSqlRelationalTableModel();
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->setTable("score_chinese");
    model->setFilter(chooseSentence);
    model->setRelation(1,QSqlRelation("info","id","name"));
    model->select();

    ui->tableView->setModel(model);
}

void ClassTeacherForm::StuAdd()
{
    QString id = ui->StudentID->text();
    QString name = ui->StudentName->text();
    QString classNum = ui->StudentClass->text();
    QString birth = ui->StudentBirth->text();
    int sex = ui->SexBox_1->currentIndex();

    bool idEmpty = false;
    bool nameEmpty = false;
    bool classEmpty = false;
    bool birthEmpty = false;
    bool sexEmpty = false;

    //判断空输入
    if(QString::compare(id,"")==0)
        idEmpty = true;
    if(QString::compare(name,"")==0)
        nameEmpty = true;
    if(QString::compare(birth,"")==0)
        birth = true;
    if(QString::compare(classNum,"")==0)
        classEmpty = true;
    if(sex == 0){                       //判断空输入并处理性别数据
        sexEmpty = true;
        sex = 3;
    }
    else
        --sex;

    //处理空输入
    if(idEmpty||nameEmpty||birthEmpty||classEmpty||sexEmpty){
        QString warnSentence = "";
        if(idEmpty)
            warnSentence.append("工号");
        if(nameEmpty)
            warnSentence.append("、姓名");
        if(birthEmpty)
            warnSentence.append("、生日");
        if(sexEmpty)
            warnSentence.append("、性别");
        if(classEmpty)
            warnSentence.append("、班级");
        if(warnSentence.startsWith("、"))
            warnSentence = warnSentence.right(warnSentence.length()-1);
        QMessageBox::warning(this,"输入错误",warnSentence+"未填写,新增学生请输入完整信息");
        return ;
    }

    if(classList.indexOf(classNum.toInt()) == -1)
        QMessageBox::warning(this,"输入错误","你没有管理该班级的权限，请联系管理员");

    QSqlQuery query;
    //添加user表
    if(!query.exec("insert into user values ("+id+",'"+name+"',3,'123456'")){
        QMessageBox::critical(nullptr, QObject::tr("数据库冲突、请检查数据"),
                              query.lastError().text());
        return;
    }
    //添加info表
    QString querySentense = "insert into teacher(id,name,class,sex,birth) "
                            "values("+id+",'"+name+"',"+classNum+","+QString::number(sex)+",'"+birth+"')";
    if(!query.exec(querySentense)){
        QMessageBox::critical(nullptr, QObject::tr("数据库冲突、请检查数据"),
                              query.lastError().text());
        return;
    }

    InfoChoose();
}

void ClassTeacherForm::StuDel()
{
    QString id = ui->StudentID->text();
    QString name = ui->StudentName->text();
    QString classNum = ui->StudentClass->text();
    QString birth = ui->StudentBirth->text();
    int sex = ui->SexBox_1->currentIndex();

    bool idEmpty = false;
    bool nameEmpty = false;
    bool classEmpty = false;
    bool birthEmpty = false;
    bool sexEmpty = false;

    //判断空输入
    if(QString::compare(id,"")==0)
        idEmpty = true;
    if(QString::compare(name,"")==0)
        nameEmpty = true;
    if(QString::compare(birth,"")==0)
        birth = true;
    if(QString::compare(classNum,"")==0)
        classEmpty = true;
    if(sex == 0){                       //判断空输入并处理性别数据
        sexEmpty = true;
        sex = 3;
    }
    else
        --sex;

    QString infoSentence = "";
    if(!idEmpty){
        if(!nameEmpty||!classEmpty||!birthEmpty||!sexEmpty){
            QMessageBox::about(this,"查询冲突","学号是单独查询条件");
            return;
        }
        infoSentence = "id = "+id;
    }
    if(!nameEmpty){
        if(!idEmpty||!classEmpty||!birthEmpty||!sexEmpty){
            QMessageBox::about(this,"查询冲突","性名是单独查询条件");
            return;
        }
        infoSentence = "name = '"+name+"'";
    }
    if(!classEmpty){
        if(!idEmpty||!nameEmpty){
            QMessageBox::about(this,"查询冲突","班级是筛选查询条件，无法对学号或姓名进行筛选");
            return;
        }
        infoSentence = "class = "+classNum;
    }
    if(!birthEmpty){
        if(!idEmpty||!nameEmpty){
            QMessageBox::about(this,"查询冲突","生日是筛选查询条件，无法对学号或姓名进行筛选");
            return;
        }
        infoSentence.append(" or birth = '"+birth+"'");
    }
    if(!sexEmpty){
        if(!idEmpty||!nameEmpty){
            QMessageBox::about(this,"查询冲突","性别是筛选查询条件，无法对学号或姓名进行筛选");
            return;
        }
        infoSentence.append(" or sex = "+QString::number(sex));
    }
    if(infoSentence.startsWith(" or"))
        infoSentence = infoSentence.right(infoSentence.length()-3);

    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("info");
    model->setFilter(infoSentence);
    if(model->select()){
        if(model->rowCount()==1){
            QSqlRecord record;
            record = model->record(0);
            qDebug()<<record.value("name").toString();
            QMessageBox::about(this,"删除成功",name+"已删除");
            model->removeRows(0,1);
            model->submitAll();
        }
        else if (model->rowCount()>1) {
            QMessageBox::about(this,"查询重复","符合该条件的学生不唯一，"
                                           "请根据右侧表格中列出的数据进一步选择，然后使用学号删除");
            ui->tableView->setModel(model);
        }
        else {
            QMessageBox::about(this,"数据库错误","请联系管理员");
        }
    }else {
        QMessageBox::about(this,"查询错误","请联系管理员");
    }

}



