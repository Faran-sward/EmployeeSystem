/****************************************************************************
** Meta object code from reading C++ file 'add_contract.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../subpage/add_contract.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'add_contract.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Add_contract_t {
    QByteArrayData data[10];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Add_contract_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Add_contract_t qt_meta_stringdata_Add_contract = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Add_contract"
QT_MOC_LITERAL(1, 13, 14), // "ToContractInfo"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 27), // "on_lineEdit_editingFinished"
QT_MOC_LITERAL(4, 57, 29), // "on_lineEdit_2_editingFinished"
QT_MOC_LITERAL(5, 87, 29), // "on_lineEdit_3_editingFinished"
QT_MOC_LITERAL(6, 117, 29), // "on_lineEdit_4_editingFinished"
QT_MOC_LITERAL(7, 147, 29), // "on_lineEdit_5_editingFinished"
QT_MOC_LITERAL(8, 177, 29), // "on_lineEdit_6_editingFinished"
QT_MOC_LITERAL(9, 207, 15) // "contract_upload"

    },
    "Add_contract\0ToContractInfo\0\0"
    "on_lineEdit_editingFinished\0"
    "on_lineEdit_2_editingFinished\0"
    "on_lineEdit_3_editingFinished\0"
    "on_lineEdit_4_editingFinished\0"
    "on_lineEdit_5_editingFinished\0"
    "on_lineEdit_6_editingFinished\0"
    "contract_upload"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Add_contract[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Add_contract::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Add_contract *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ToContractInfo(); break;
        case 1: _t->on_lineEdit_editingFinished(); break;
        case 2: _t->on_lineEdit_2_editingFinished(); break;
        case 3: _t->on_lineEdit_3_editingFinished(); break;
        case 4: _t->on_lineEdit_4_editingFinished(); break;
        case 5: _t->on_lineEdit_5_editingFinished(); break;
        case 6: _t->on_lineEdit_6_editingFinished(); break;
        case 7: _t->contract_upload(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Add_contract::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Add_contract::ToContractInfo)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Add_contract::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Add_contract.data,
    qt_meta_data_Add_contract,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Add_contract::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Add_contract::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Add_contract.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Add_contract::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Add_contract::ToContractInfo()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
