/**
 * @file mainwindow.h
 * @authors xdolez0c, xvecer30, xpolia05, xloren16
 * @brief The main logic and functionality of the Calculator using the math
 * library and UI buttons.
 * @version 1.0
 * @date 2022-04-28
 */

#include "mainwindow.h"
#include <string.h>
#include <QDebug>
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Connecting UI buttons with methods.
    connect(ui->pushButton_0, &QPushButton::clicked, this, &MainWindow::Print0);
    connect(ui->pushButton_1, &QPushButton::clicked, this, &MainWindow::Print1);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::Print2);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::Print3);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::Print4);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::Print5);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::Print6);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::Print7);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::Print8);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::Print9);
    connect(ui->pushButton_dot, &QPushButton::clicked, this,
            &MainWindow::PrintDot);
    connect(ui->pushButton_C, &QPushButton::clicked, this,
            &MainWindow::ClearDisplays);
    connect(ui->pushButton_delete, &QPushButton::clicked, this,
            &MainWindow::Delete);
    connect(ui->pushButton_plus, &QPushButton::clicked, this,
            &MainWindow::OperatorPlus);
    connect(ui->pushButton_div, &QPushButton::clicked, this,
            &MainWindow::OperatorDiv);
    connect(ui->pushButton_fac, &QPushButton::clicked, this,
            &MainWindow::OperatorFac);
    connect(ui->pushButton_mul, &QPushButton::clicked, this,
            &MainWindow::OperatorMul);
    connect(ui->pushButton_sub, &QPushButton::clicked, this,
            &MainWindow::OperatorSub);
    connect(ui->pushButton_sign, &QPushButton::clicked, this,
            &MainWindow::OperatorSign);
    connect(ui->pushButton_result, &QPushButton::clicked, this,
            &MainWindow::OperatorResult);
    connect(ui->pushButton_modulo, &QPushButton::clicked, this,
            &MainWindow::OperatorModulo);
    connect(ui->pushButton_exp, &QPushButton::clicked, this,
            &MainWindow::OperatorExp);
    connect(ui->pushButton_sqrt, &QPushButton::clicked, this,
            &MainWindow::OperatorSqrt);
    connect(ui->pushButton_divwithoutreminder, &QPushButton::clicked, this,
            &MainWindow::OperatorDivnoReminder);
    connect(ui->help, &QAction::triggered, this, &MainWindow::ShowHideToggle);

    // Inicialization of bool variables and states of the UI.
    is_error = false;
    first_operator = true;
    is_result = false;
    is_dot = false;
    func.fncptr_dd = nullptr;
    func.fncptr_di = nullptr;
    result_display_clear = true;
    ui->ResultDisplay->setText("0");
    ui->hint_window->setVisible(false);
}

MainWindow::~MainWindow() {
    delete ui;
}

/**
 * @brief Deletes the last digit from the Result display.
 *
 */
void MainWindow::Delete() {
    int display_len = (ui->ResultDisplay->text()).length();
    if (display_len != 0) {
        if (ui->ResultDisplay->text().at(0) == '-' && (display_len == 2)) {
            ui->ResultDisplay->setText("0");
        } else if (display_len == 1) {
            ui->ResultDisplay->setText("0");
        } else {
            if (ui->ResultDisplay->text().at(display_len - 1) == '.') {
                is_dot = false;
            }
            ui->ResultDisplay->setText(
                (ui->ResultDisplay->text()).remove(display_len - 1, 1));
        }
    }
}

/**
 * @brief sets the visibility of Hint window to true if hidden, and false if
 * shown.
 */
void MainWindow::ShowHideToggle() {
    if (ui->hint_window->isVisible()) {
        ui->hint_window->setVisible(false);
    } else {
        ui->hint_window->setVisible(true);
    }
}

/**
 * @brief Deletes the content in Calculation and Result display.
 */
void MainWindow::ClearDisplays() {
    ClearCalculationDisplay();
    ClearResultDisplay();
    ui->ResultDisplay->setText("0");
    first_operator = true;
    is_result = false;
}

/**
 * @brief Deletes the content of Result display.
 */
void MainWindow::ClearResultDisplay() {
    result_display_clear = true;
    ui->ResultDisplay->clear();
    is_dot = false;
}

/**
 * @brief Deletes the content of Calculation display.
 */
void MainWindow::ClearCalculationDisplay() {
    ui->CalculationDisplay->clear();
    is_dot = false;
}

/**
 * @brief Prints number 0 to the Result display.
 */
void MainWindow::Print0() {
    int display_len = (ui->ResultDisplay->text()).length();
    result_display_clear = false;
    if (((ui->ResultDisplay->text()).toDouble() == 0 && display_len <= 1) ||
        is_error || is_result) {
        ClearResultDisplay();
        ui->ResultDisplay->setText("0");
        result_display_clear = false;
        is_result = 0;
        is_error = 0;

    } else {
        ui->ResultDisplay->setText(ui->ResultDisplay->text() + "0");
    }
}

/**
 * @brief Prints number 1 to the Result display
 */
void MainWindow::Print1() {
    int display_len = (ui->ResultDisplay->text()).length();
    result_display_clear = false;
    if (((ui->ResultDisplay->text()).toDouble() == 0 && display_len <= 1) ||
        is_error || is_result) {
        ClearResultDisplay();
        ui->ResultDisplay->setText("1");
        result_display_clear = false;
        is_result = 0;
        is_error = 0;
    } else {
        ui->ResultDisplay->setText(ui->ResultDisplay->text() + "1");
    }
}

/**
 * @brief Prints number 2 to the Result display
 */
void MainWindow::Print2() {
    int display_len = (ui->ResultDisplay->text()).length();
    result_display_clear = false;
    if (((ui->ResultDisplay->text()).toDouble() == 0 && display_len <= 1) ||
        is_error || is_result) {
        ClearResultDisplay();
        ui->ResultDisplay->setText("2");
        result_display_clear = false;
        is_result = 0;
        is_error = 0;
    } else {
        ui->ResultDisplay->setText(ui->ResultDisplay->text() + "2");
    }
}

/**
 * @brief Prints number 3 to the Result display
 */
void MainWindow::Print3() {
    int display_len = (ui->ResultDisplay->text()).length();
    result_display_clear = false;
    if (((ui->ResultDisplay->text()).toDouble() == 0 && display_len <= 1) ||
        is_error || is_result) {
        ClearResultDisplay();
        result_display_clear = false;
        ui->ResultDisplay->setText("3");
        is_result = 0;
        is_error = 0;
    } else {
        ui->ResultDisplay->setText(ui->ResultDisplay->text() + "3");
    }
}

/**
 * @brief Prints number 4 to the Result display
 */
void MainWindow::Print4() {
    int display_len = (ui->ResultDisplay->text()).length();
    result_display_clear = false;
    if (((ui->ResultDisplay->text()).toDouble() == 0 && display_len <= 1) ||
        is_error || is_result) {
        ClearResultDisplay();
        ui->ResultDisplay->setText("4");
        result_display_clear = false;
        is_result = 0;
        is_error = 0;
    } else {
        ui->ResultDisplay->setText(ui->ResultDisplay->text() + "4");
    }
}

/**
 * @brief Prints number 5 to the Result display
 */
void MainWindow::Print5() {
    int display_len = (ui->ResultDisplay->text()).length();
    result_display_clear = false;
    if (((ui->ResultDisplay->text()).toDouble() == 0 && display_len <= 1) ||
        is_error || is_result) {
        ClearResultDisplay();
        ui->ResultDisplay->setText("5");
        result_display_clear = false;
        is_result = 0;
        is_error = 0;
    } else {
        ui->ResultDisplay->setText(ui->ResultDisplay->text() + "5");
        result_display_clear = false;
    }
}

/**
 * @brief Prints number 6 to the Result display
 */
void MainWindow::Print6() {
    int display_len = (ui->ResultDisplay->text()).length();
    result_display_clear = false;
    if (((ui->ResultDisplay->text()).toDouble() == 0 && display_len <= 1) ||
        is_error || is_result) {
        ClearResultDisplay();
        ui->ResultDisplay->setText("6");
        result_display_clear = false;
        is_result = 0;
        is_error = 0;
    } else {
        ui->ResultDisplay->setText(ui->ResultDisplay->text() + "6");
    }
}

/**
 * @brief Prints number 7 to the Result display
 */
void MainWindow::Print7() {
    int display_len = (ui->ResultDisplay->text()).length();
    result_display_clear = false;
    if (((ui->ResultDisplay->text()).toDouble() == 0 && display_len <= 1) ||
        is_error || is_result) {
        ClearResultDisplay();
        ui->ResultDisplay->setText("7");
        result_display_clear = false;
        is_result = 0;
        is_error = 0;
    } else {
        ui->ResultDisplay->setText(ui->ResultDisplay->text() + "7");
    }
}

/**
 * @brief Prints number 8 to the Result display
 */
void MainWindow::Print8() {
    int display_len = (ui->ResultDisplay->text()).length();
    result_display_clear = false;
    if (((ui->ResultDisplay->text()).toDouble() == 0 && display_len <= 1) ||
        is_error || is_result) {
        ClearResultDisplay();
        ui->ResultDisplay->setText("8");
        result_display_clear = false;
        is_result = 0;
        is_error = 0;
    } else {
        ui->ResultDisplay->setText(ui->ResultDisplay->text() + "8");
    }
}

/**
 * @brief Prints number 9 to the Result display
 */
void MainWindow::Print9() {
    int display_len = (ui->ResultDisplay->text()).length();
    result_display_clear = false;
    if (((ui->ResultDisplay->text()).toDouble() == 0 && display_len <= 1) ||
        is_error || is_result) {
        ClearResultDisplay();
        ui->ResultDisplay->setText("9");
        result_display_clear = false;
        is_result = 0;
        is_error = 0;
    } else {
        ui->ResultDisplay->setText(ui->ResultDisplay->text() + "9");
    }
}

/**
 * @brief Stores the number in Result display as a first operand number. Sets
 * the used operation to Add.
 */
void MainWindow::OperatorPlus() {
    if (first_operator == true) {
        result1 = (ui->ResultDisplay->text()).toDouble();
        ui->CalculationDisplay->setText(ui->ResultDisplay->text() + ' ' + '+');
        first_operator = false;
    } else {
        int display_len = ui->CalculationDisplay->text().length();
        ui->CalculationDisplay->setText(
            (ui->CalculationDisplay->text()).remove(display_len - 1, 1));
        ui->CalculationDisplay->setText(ui->CalculationDisplay->text() + '+');
    }
    ClearResultDisplay();
    func.fncptr_dd = &math_lib_t::add;
    func.fncptr_di = nullptr;
    is_dot = false;
}

/**
 * @brief Stores the number in Result display as a first operand number. Sets
 * the used operation to Multiply.
 */
void MainWindow::OperatorMul() {
    if (first_operator == true) {
        result1 = (ui->ResultDisplay->text()).toDouble();
        ui->CalculationDisplay->setText(ui->ResultDisplay->text() + ' ' + "*");
        first_operator = false;
    } else {
        int display_len = (ui->CalculationDisplay->text()).length();
        ui->CalculationDisplay->setText(
            (ui->CalculationDisplay->text()).remove(display_len - 1, 1));
        ui->CalculationDisplay->setText(ui->CalculationDisplay->text() + '*');
    }
    ClearResultDisplay();
    func.fncptr_dd = &math_lib_t::mult;
    func.fncptr_di = nullptr;
    is_dot = false;
}

/**
 * @brief Stores the number in Result display as a first operand number. Sets
 * the used operation to Divide.
 */
void MainWindow::OperatorDiv() {
    if (first_operator == true) {
        result1 = (ui->ResultDisplay->text()).toDouble();
        ui->CalculationDisplay->setText(ui->ResultDisplay->text() + ' ' + "/");
        first_operator = false;
    } else {
        int display_len = ui->CalculationDisplay->text().length();
        ui->CalculationDisplay->setText(
            (ui->CalculationDisplay->text()).remove(display_len - 1, 1));
        ui->CalculationDisplay->setText(ui->CalculationDisplay->text() + '/');
    }
    ClearResultDisplay();
    func.fncptr_dd = &math_lib_t::div;
    func.fncptr_di = nullptr;
    is_dot = false;
}

/**
 * @brief Stores the number in Result display as a first operand number. Sets
 * the used operation Substract.
 */
void MainWindow::OperatorSub() {
    if (first_operator == true) {
        result1 = (ui->ResultDisplay->text()).toDouble();
        ui->CalculationDisplay->setText(ui->ResultDisplay->text() + ' ' + "-");
        first_operator = false;
    } else {
        int display_len = ui->CalculationDisplay->text().length();
        ui->CalculationDisplay->setText(
            (ui->CalculationDisplay->text()).remove(display_len - 1, 1));
        ui->CalculationDisplay->setText(ui->CalculationDisplay->text() + '-');
    }
    ClearResultDisplay();
    func.fncptr_dd = &math_lib_t::sub;
    func.fncptr_di = nullptr;
    is_dot = false;
}

/**
 * @brief Takes the number from the Result display and does factorial with it.
 */
void MainWindow::OperatorFac() {
    int display_result = (ui->ResultDisplay->text()).toDouble();
    int result;
    try {
        ui->CalculationDisplay->setText(QString::number(display_result) + '!');
        result = calculator.fact(display_result);
        ui->ResultDisplay->setText(QString::number(result));
        is_result = 1;
    } catch (const std::runtime_error& e) {
        is_error = 1;
        ui->ResultDisplay->setText(e.what());
    }
    is_dot = false;
}

/**
 * @brief Toggles sign of the number in result display.
 */
void MainWindow::OperatorSign() {
    if ((ui->ResultDisplay->text().length() != 0) &&
        (ui->ResultDisplay->text().at(0) != '0' || is_dot == true)) {
        if (ui->ResultDisplay->text().at(0) == '-') {
            ui->ResultDisplay->setText(
                (ui->ResultDisplay->text()).remove(0, 1));
        } else {
            ui->ResultDisplay->setText('-' + ui->ResultDisplay->text());
        }
    }
}

/**
 * @brief Stores the number in Calculation display as a second operand, Takes
 * the first operand and second operand and calls a selected function
 * from the math library, and prints the result to the result display
 *
 */
void MainWindow::OperatorResult() {
    if ((func.fncptr_dd != nullptr) || (func.fncptr_di != nullptr)) {
        is_result = true;
        first_operator = true;
        result2 = (ui->ResultDisplay->text()).toDouble();
        ui->CalculationDisplay->setText(ui->CalculationDisplay->text() + ' ' +
                                        QString::number(result2) + ' ' + '=');
        try {
            if (func.fncptr_dd != nullptr) {
                ui->ResultDisplay->setText(
                    QString::number(func.fncptr_dd(result1, result2)));
            } else {
                ui->ResultDisplay->setText(
                    QString::number(func.fncptr_di(result1, result2)));
            }
            func.fncptr_dd = nullptr;
            func.fncptr_di = nullptr;
        } catch (const std::runtime_error& e) {
            is_error = 1;
            ui->ResultDisplay->setText(e.what());
        }
    }
}

/**
 * @brief Stores the number in Result display as a first operand and sets the
 * used function to Div.
 *
 */
void MainWindow::OperatorDivnoReminder() {
    if (first_operator == true) {
        result1 = (ui->ResultDisplay->text()).toDouble();
        ui->CalculationDisplay->setText(ui->ResultDisplay->text() + ' ' + "/");
        first_operator = false;
    } else {
        int display_len = ui->CalculationDisplay->text().length();
        ui->CalculationDisplay->setText(
            (ui->CalculationDisplay->text()).remove(display_len - 1, 1));
        ui->CalculationDisplay->setText(ui->CalculationDisplay->text() + "/");
    }
    func.fncptr_dd = &math_lib_t::divisionWithoutRemainder;
    func.fncptr_di = nullptr;
    ClearResultDisplay();
    is_dot = false;
}

/**
 * @brief Stores the number in a Result display as a first operand and sets the
 * used function to Modulo.
 *
 */
void MainWindow::OperatorModulo() {
    if (first_operator == true) {
        result1 = (ui->ResultDisplay->text()).toDouble();
        ui->CalculationDisplay->setText(ui->ResultDisplay->text() + ' ' + "%");
        first_operator = false;
    } else {
        int display_len = ui->CalculationDisplay->text().length();
        ui->CalculationDisplay->setText(
            (ui->CalculationDisplay->text()).remove(display_len - 1, 1));
        ui->CalculationDisplay->setText(ui->CalculationDisplay->text() + "%");
    }
    func.fncptr_dd = &math_lib_t::modulo;
    func.fncptr_di = nullptr;
    ClearResultDisplay();
    is_dot = false;
}

/**
 * @brief Stores the number in a Result display as a first operand and sets the
 * used function to Root.
 */
void MainWindow::OperatorSqrt() {
    if (first_operator == true) {
        result1 = (ui->ResultDisplay->text()).toDouble();
        ui->CalculationDisplay->setText(ui->ResultDisplay->text() + ' ' + "s");
        first_operator = false;
    } else {
        int display_len = ui->CalculationDisplay->text().length();
        ui->CalculationDisplay->setText(
            (ui->CalculationDisplay->text()).remove(display_len - 1, 1));
        ui->CalculationDisplay->setText(ui->CalculationDisplay->text() + "s");
    }
    func.fncptr_di = &math_lib_t::my_sqrt;
    func.fncptr_dd = nullptr;
    ClearResultDisplay();
    is_dot = false;
}

/**
 * @brief Stores the number in a Result display as a first operand and sets the
 * used function to Exponent.
 */
void MainWindow::OperatorExp() {
    if (first_operator == true) {
        result1 = (ui->ResultDisplay->text()).toDouble();
        ui->CalculationDisplay->setText(ui->ResultDisplay->text() + ' ' + '^');
        first_operator = false;
    } else {
        int display_len = ui->CalculationDisplay->text().length();
        ui->CalculationDisplay->setText(
            (ui->CalculationDisplay->text()).remove(display_len - 1, 1));
        ui->CalculationDisplay->setText(ui->CalculationDisplay->text() + '^');
    }
    func.fncptr_di = &math_lib_t::exp;
    func.fncptr_dd = nullptr;
    ClearResultDisplay();
    is_dot = false;
}
/**
 * @brief Adds dot to a intiger number.
 *
 */
void MainWindow::PrintDot() {
    int display_len = (ui->ResultDisplay->text()).length();
    if (display_len > 0 && is_dot == false && is_result == false) {
        ui->ResultDisplay->setText(ui->ResultDisplay->text() + ".");
        is_dot = true;
    }
}

/** END OF FILE */