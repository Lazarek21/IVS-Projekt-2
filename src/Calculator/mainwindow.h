/**
 * @file mainwindow.h
 * @authors xdolez0c, xvecer30, xpolia05, xloren16
 * @brief .h file of the mainwindow.
 * @version 1.0
 * @date 2022-04-28
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../lib/math_lib.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    math_lib_t calculator;
    double result1;
    double result2;
    typedef struct {
        double (*fncptr_dd)(double, double);
        double (*fncptr_di)(double, int);
    } func_ptr;
    func_ptr func;
    bool is_error;
    bool first_operator;
    bool is_result;
    bool result_display_clear;
    bool is_dot;
    bool is_hidden;
    MainWindow(QWidget* parent = nullptr);
    void Delete();
    void ClearDisplays();
    void ClearCalculationDisplay();
    void ClearResultDisplay();
    void Print0();
    void Print1();
    void Print2();
    void Print3();
    void Print4();
    void Print5();
    void Print6();
    void Print7();
    void Print8();
    void Print9();
    void PrintDot();
    void OperatorPlus();
    void OperatorMul();
    void OperatorDiv();
    void OperatorSub();
    void OperatorFac();
    void OperatorSign();
    void OperatorResult();
    void OperatorDivnoReminder();
    void OperatorModulo();
    void OperatorSqrt();
    void OperatorExp();
    void ShowHideToggle();

    void PrintNumber(int num);
    ~MainWindow();

   private:
    Ui::MainWindow* ui;
};
#endif  // MAINWINDOW_H

/** END OF FILE */