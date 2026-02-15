#ifndef GLOBAL_H
#define GLOBAL_H

#include <QWidget>
#include <functional>
#include <memory>
#include <iostream>
#include <mutex>

#include "Qstyle"

//用来刷新qss的
extern std::function<void(QWidget*)> repolish;

#endif
