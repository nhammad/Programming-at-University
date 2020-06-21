/** 
 *  @file   instructordialog.h
 *  @brief  This is the window of the game that pops up for instructor after login.
 ***************************************************************************************/

#ifndef INSTRUCTORDIALOG_H
#define INSTRUCTORDIALOG_H

#include <QDialog>

#include "../backend/instructor.h"

class Instructor;
namespace Ui
{
class InstructorDialog;
}

/// @brief Class for setting the window for instructor in Beer Game
class InstructorDialog : public QDialog
{
    Q_OBJECT

public:
    QWidget *parent;

    /// @brief Construct a instructor dialog
    /// @param parent  The parent ui for the class
    explicit InstructorDialog(QWidget *parent = nullptr);

    /// Default destructor
    ~InstructorDialog();

    /// @brief Method to update the UI of the instructor class
    void updateInstructorUI();

    /// @brief Pointer of the instructor linked with this instructordialog
    Instructor *instructor;

    /// @brief The ui of window
    Ui::InstructorDialog *ui;

private slots:
    /// @brief Method that runs when the create game button is clicked
    void on_createGame_clicked();

    /// @brief Method for instructor to exit the game
    void on_ins_exitbtn_clicked();

};

#endif // INSTRUCTORDIALOG_H
