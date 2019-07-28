#include "Python.h"

static PyObject *monkeypatch(PyObject *self, PyObject *args) {
    PyObject *target;
    PyObject *attr_name;
    PyObject *attr_val;

    if(!PyArg_ParseTuple(args, "OOO", &target, &attr_name, &attr_val))
        return NULL;

    _PyObject_GenericSetAttrWithDict(target, attr_name, attr_val, NULL);

    Py_RETURN_NONE;
}

struct PyMethodDef methods[] = {
    { "monkeypatch", monkeypatch, METH_VARARGS, "" },
    { 0 },
};

struct PyModuleDef module = {
    .m_base = PyModuleDef_HEAD_INIT,
    .m_name = "monkeypatch",
    .m_doc = "",
    .m_size = 0,
    .m_methods = methods,
};

PyMODINIT_FUNC PyInit_monkeypatch(void) {
    PyModule_Create(&module);
}
