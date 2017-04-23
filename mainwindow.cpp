#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<dialog.h> //for displaying dialog box of help
#include<font.h>   //for displaying font dialog box
#include<QtCore>  //For Qstring
#include<QtGui>   //For Qstring
#include<QMessageBox> //For including Message in the about section
#include<QFile>  //For opening ,Saving etc
#include<QFileDialog>
#include<QTextStream> //For streams related to Opening ,Saving etc
#include<QMessageBox>
#include<QString>
#include<iostream>
#include<QPrinter> //For printing
#include<QPrintDialog> //For printing
#include<QPrintPreviewDialog> //For previewing the document to be printed
#include<QPainter>
#include<QKeySequence>  // for linking actions with inbuilt shortcut keys
#include<QDateTime>     // implemented for date and time
#include<QList>
#include<QMap>  //for word count
#include <fstream>
#include <cstdlib>
#include <cctype>
#include<qtconcurrentmap.h> //for word count

using namespace QtConcurrent; //for word count
typedef QMap<QString, int> WordCount; //for word count

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit); //For covering the whole central area for writing

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    Filepath="";
    Filename ="untitled"; //For initial name of new file that will be created
    ui->textEdit->setPlainText("/*     Type your text here     */");
    count++;
}


void MainWindow::on_actionNew_Window_triggered()
{

}

void MainWindow::on_actionOpen_triggered()
{
    Filename=QFileDialog::getOpenFileName(this,"Open A File"); //Third argument can be provided for default location
    QFile file(Filename);
    Filepath=Filename; //for save function
    if(!file.open(QFile::ReadOnly | QFile::Text)) //For checking if the file is open or not also checking if the file is read only and is a text file
    {
    //QMessageBox::warning(this,"Error","File Not Open"); //Message that will be displayed when we are unable to open file
    return ; //this will terminate the process as the condition is not satisfied
    }
    QTextStream in(&file); //opening the file
    QString text =in.readAll(); //for reading the text we are writing on new file
    ui->textEdit->setText(text);  //for setting the default text to written text
    file.close();
}

void MainWindow::on_actionOpen_Project_s_triggered()
{

}

void MainWindow::on_actionSave_triggered()
{
    QFile file(Filepath); //Filepath already saved in open
    if(!file.open(QFile::WriteOnly | QFile::Text)) /*for checking if the file is open or not also checking if the file is write only and is a text file*/
    {
    //QMessageBox::warning(this,"Error","File Not Open"); //Message that will be displayed when we are unable to open file
    return ; //this will terminate the process as the condition is not satisfied
    }
    QTextStream out(&file); //saving the file
    QString text =ui->textEdit->toPlainText(); //for getting the text from text edit
    out<<text;
    file.flush();
    file.close();
}

void MainWindow::on_actionSave_As_triggered()
{
    Filename=QFileDialog::getSaveFileName(this,"Save A File"); //Third argument can be provided for default location
    QFile file(Filename);
    Filepath=Filename; //for saving the file
    if(!file.open(QFile::WriteOnly | QFile::Text)) //for checking if the file is open or not also checking if the file is write only and is a text file
    {
    //QMessageBox::warning(this,"Error","File Not Open"); //Message that will be displayed when we are unable to open file
    return ; //this will terminate the process as the condition is not satisfied
    }
    QTextStream out(&file); //saving the file
    QString text =ui->textEdit->toPlainText(); //for getting the text from text edit
    out<<text;
    file.flush();
    file.close();
}

void MainWindow::on_actionClose_triggered()
{
/*QFile file(Filename);
Filepath=Filename;
if(file.isOpen())
{
file.close();
}
*/
    QString x=QString::number(count);   //converting the rank of new file created into string
     QMessageBox::StandardButton reply;
    /*QMessageBox ::question(this,"Text Editor","Do you want to save the ");*/
    QString y=Filename;
    if(Filename=="untitled")
    {
        y = y + x;  // works only if new file is created
    }
    else
    {
        QString str=Filepath;
        QStringList parts = str.split("/");
        QString lastBit = parts.at(parts.size()-1);
        y=lastBit;
    }
    QString status=QString("Do you want to save the "+y);
    reply=QMessageBox ::question(this,"Text Editor",status);
     if (reply == QMessageBox::Yes)
     {
         if(Filename!="untitled")
         {
             QFile file(Filepath); //Filepath already saved in open
             if(!file.open(QFile::WriteOnly | QFile::Text)) /*for checking if the file is open or not also checking if the file is write only and is a text file*/
             {
             //QMessageBox::warning(this,"Error","File Not Open"); //Message that will be displayed when we are unable to open file
             return ; //this will terminate the process as the condition is not satisfied
             }
             QTextStream out(&file); //saving the file
             QString text =ui->textEdit->toPlainText(); //for getting the text from text edit
             out<<text;
             file.flush();
             file.close();
         }
         else
         {
             Filename=QFileDialog::getSaveFileName(this,"Save A File"); //Third argument can be provided for default location
             QFile file(Filename);
             Filepath=Filename; //for saving the file
             if(!file.open(QFile::WriteOnly | QFile::Text)) //for checking if the file is open or not also checking if the file is write only and is a text file
             {
             //QMessageBox::warning(this,"Error","File Not Open"); //Message that will be displayed when we are unable to open file
             return ; //this will terminate the process as the condition is not satisfied
             }
             QTextStream out(&file); //saving the file
             QString text =ui->textEdit->toPlainText(); //for getting the text from text edit
             out<<text;
             file.flush();
             file.close();
         }
         //save code
         this->close();
     }
     else
     {
        this->close();
     }
}

void MainWindow::on_actionClose_Window_triggered()
{

}

void MainWindow::on_actionReopen_Project_triggered()
{

}

void MainWindow::on_actionReopen_Last_Item_triggered()
{

}

void MainWindow::on_actionProperties_triggered()
{

}

void MainWindow::on_actionPage_Setup_triggered()
{

}

void MainWindow::on_actionPDF_triggered()
{

}

void MainWindow::on_actionHTML_triggered()
{

}

void MainWindow::on_actionXML_triggered()
{

}

void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()==QDialog::Rejected) //checking if the printer is working
    {
        return ;
    }
    else
    {
        ui->textEdit->print(&printer);
    }
}

void MainWindow::on_actionPrint_Preview_triggered()
{
    /*
    // display print preview dialog
      QPrinter             printer( QPrinter::HighResolution );
      QPrintPreviewDialog  preview( &printer, this );
      QPainter painter(&printer);
          painter.setWindow(this->rect());
          this->render(&painter);
      //connect( &preview, SIGNAL(paintRequested(QPrinter*)), SLOT(print(QPrinter*)) );
      preview.exec();
      /*if(preview.exec()==QPrintPreviewDialog::Rejected) //checking if the printer is working
      {
          return ;
      }*/
      //else
      //{
          //ui->textEdit->print(&printer);
      //}

}

void MainWindow::on_actionClose_All_Tabs_triggered()
{

}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionDelete_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();//The QTextCursor class offers an API to access and modify QTextDocuments.
        if(cursor.hasSelection())
        {
            cursor.deleteChar(); //deletes the selected text
            //QTextCursor contains information about both the cursor's position within a
            //  QTextDocument and any selection that it has made.
        }
        else
        {
            cursor.deletePreviousChar(); //deletes the previous text like when we press delete the cursor removes the previous char
        }
}

void MainWindow::on_actionSelect_All_triggered()
{
    ui->textEdit->selectAll();
}

void MainWindow::on_actionIndent_triggered()
{

}

void MainWindow::on_actionNext_triggered()
{

}

void MainWindow::on_actionPrevious_triggered()
{

}

void MainWindow::on_actionToggle_triggered()
{

}

void MainWindow::on_actionDelete_2_triggered()
{

}

void MainWindow::on_actionPreferences_triggered()
{

}

void MainWindow::on_actionOutdent_triggered()
{

}

void MainWindow::on_actionFolding_triggered()
{

}

void MainWindow::on_actionSnippet_triggered()
{

}

void MainWindow::on_actionTime_Date_triggered()
{
     QDateTime now = QDateTime::currentDateTime(); //for getting date/time from system
     QString now1=now.toString("yyyy-MM-dd hh:mm:ss"); //converting to string and specifying format
     QMessageBox::information(this,"Date/Time",now1); //displaying string
}

void MainWindow::on_actionUppercase_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();//The QTextCursor class offers an API to access and modify QTextDocuments.
        if(cursor.hasSelection())
        {
            cursor.insertText(cursor.selectedText().toUpper());
            //QTextCursor contains information about both the cursor's position within a
            //  QTextDocument and any selection that it has made.
        }
}

void MainWindow::on_actionLowercase_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();//The QTextCursor class offers an API to access and modify QTextDocuments.
        if(cursor.hasSelection())
        {
            cursor.insertText(cursor.selectedText().toLower());
            //QTextCursor contains information about both the cursor's position within a
            //  QTextDocument and any selection that it has made.
        }
}

void MainWindow::on_actionSearch_triggered()
{

}

void MainWindow::on_actionFind_Next_triggered()
{

}

void MainWindow::on_actionFind_Previous_triggered()
{

}

void MainWindow::on_actionReplace_triggered()
{

}

void MainWindow::on_actionQuick_FInd_triggered()
{

}

void MainWindow::on_actionFind_in_Files_triggered()
{

}

void MainWindow::on_actionNext_Tab_triggered()
{

}

void MainWindow::on_actionShrink_Font_triggered()
{

}

void MainWindow::on_actionChange_Font_triggered()
{
    QFont f( "Arial", 10, QFont::Bold);
      ui->textEdit->setFont( f);
    //QApplication::setFont();
}

void MainWindow::on_actionNext_Tab_2_triggered()
{

}

void MainWindow::on_actionPrevious_Tab_triggered()
{

}

void MainWindow::on_actionChange_Color_triggered()
{

}

void MainWindow::on_actionHide_Tab_triggered()
{

}

void MainWindow::on_actionEnter_Fullscreen_triggered()
{
    QWidget::showFullScreen();  //for maximizing again after minmizing
    QWidget::showMaximized();   //maximize function
}


void MainWindow::on_actionHide_Minimap_triggered()
{

}

void MainWindow::on_actionWord_Wrap_triggered()
{

}

void MainWindow::on_actionTree_View_triggered()
{

}

void MainWindow::on_actionSpell_Check_triggered()
{

}

void MainWindow::on_actionWord_Count_triggered()
{

        QFile f(Filename);
        f.open(QIODevice::ReadOnly);
        QTextStream textStream(&f);
        int wordCount=0;

        while (textStream.atEnd() == false)
            foreach (QString word, textStream.readLine().split(" "))
                wordCount += 1;

         QString x=QString::number(wordCount);  //for converting integer to string


        QMessageBox::information(this,"Word Count",x);


/*
    void countStuff(istream& in,
                    int& chars,
                    int& words,
                    int& lines) {

       char cur = '\0';
       char last = '\0';
       chars = words = lines = 0;

       while (in.get(cur)) {
          if (cur == '\n' ||
              (cur == '\f' && last == '\r'))
             lines++;
          else
            chars++;
          if (!std::isalnum(cur) &&   // This is the end of a
              std::isalnum(last))     // word
             words++;
          last = cur;
       }
       if (chars > 0) {               // Adjust word and line
          if (std::isalnum(last))     // counts for special
             words++;                 // case
          lines++;
       }
    }



    if (argc < 2)
       return(EXIT_FAILURE);

    ifstream in(argv[1]);

    if (!in)
       exit(EXIT_FAILURE);

    int c, w, l;

    countStuff(in, c, w, l);
    QString s1=c.toString();
    QString s2=w.toString();
    QString s3=l.toString();

    QMessageBox::information(this,"chars,lines,words",s1+" "+s2+" "+s3);

*/
}

void MainWindow::on_actionBracket_Matcher_triggered()
{

}

void MainWindow::on_actionSelect_Inside_of_Brackets_triggered()
{
}


void MainWindow::on_actionExit_triggered()
{
    qApp->quit();    //For exiting via drop down
}

void MainWindow::on_actionAbout_triggered()
{
    Dialog *dialog=new Dialog(this);
    dialog->setWindowModality(Qt::WindowModal);
    dialog->show();
}

void MainWindow::on_actionMinimize_triggered()
{
    QWidget::showFullScreen();  //for minimizing again after maximizing
    QWidget::showMinimized();   //minimizing function
}

void MainWindow::on_actionFont_2_triggered()
{
    Font *font=new Font(this);
    font->setWindowModality(Qt::WindowModal);
    font->setFixedSize(400,300);  //for setting size of dialog box
    font->show();



}
