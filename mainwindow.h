#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtCore> //For Qstring
#include<QtGui>  //For Qstring

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionNew_Window_triggered();

    void on_actionOpen_triggered();

    void on_actionOpen_Project_s_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionClose_triggered();

    void on_actionClose_Window_triggered();

    void on_actionReopen_Project_triggered();

    void on_actionReopen_Last_Item_triggered();

    void on_actionProperties_triggered();

    void on_actionPage_Setup_triggered();

    void on_actionPDF_triggered();

    void on_actionHTML_triggered();

    void on_actionXML_triggered();

    void on_actionPrint_triggered();

    void on_actionPrint_Preview_triggered();

    void on_actionClose_All_Tabs_triggered();

    void on_actionExit_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionDelete_triggered();

    void on_actionSelect_All_triggered();

    void on_actionIndent_triggered();

    void on_actionNext_triggered();

    void on_actionPrevious_triggered();

    void on_actionToggle_triggered();

    void on_actionDelete_2_triggered();

    void on_actionPreferences_triggered();

    void on_actionOutdent_triggered();

    void on_actionFolding_triggered();

    void on_actionSnippet_triggered();

    void on_actionTime_Date_triggered();

    void on_actionUppercase_triggered();

    void on_actionLowercase_triggered();

    void on_actionSearch_triggered();

    void on_actionFind_Next_triggered();

    void on_actionFind_Previous_triggered();

    void on_actionReplace_triggered();

    void on_actionQuick_FInd_triggered();

    void on_actionFind_in_Files_triggered();

    void on_actionNext_Tab_triggered();

    void on_actionShrink_Font_triggered();

    void on_actionChange_Font_triggered();

    void on_actionNext_Tab_2_triggered();

    void on_actionPrevious_Tab_triggered();

    void on_actionChange_Color_triggered();

    void on_actionHide_Tab_triggered();

    void on_actionEnter_Fullscreen_triggered();

    void on_actionHide_Minimap_triggered();

    void on_actionWord_Wrap_triggered();

    void on_actionTree_View_triggered();

    void on_actionSpell_Check_triggered();

    void on_actionWord_Count_triggered();

    void on_actionBracket_Matcher_triggered();

    void on_actionSelect_Inside_of_Brackets_triggered();

    void on_actionAbout_triggered();

    void on_actionMinimize_triggered();

    void on_actionFont_2_triggered();

private:
    Ui::MainWindow *ui;
    QString Filename; //For creatting default name of a new file
    QString Filepath; //For filepath
    int count=0;    // count keeps the number of new file whose name is "untitled"
};

#endif // MAINWINDOW_H
