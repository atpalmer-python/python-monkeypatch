#include "Python.h"

PyDoc_STRVAR(module__doc__,
    "Provides an interface to add user-defined attributes to built-in types.");

PyDoc_STRVAR(monkeypatch__doc__, "Patch built-in types with custom attributes.");
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
    {"monkeypatch", monkeypatch, METH_VARARGS, monkeypatch__doc__},
    {0},
};

struct PyModuleDef module = {
    .m_base = PyModuleDef_HEAD_INIT,
    .m_name = "monkeypatch",
    .m_doc = module__doc__,
    .m_size = 0,
    .m_methods = methods,
};

PyMODINIT_FUNC PyInit_monkeypatch(void) {
    PyModule_Create(&module);
}
