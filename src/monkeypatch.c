#include "Python.h"

PyDoc_STRVAR(module__doc__,
    "Provides an interface to add user-defined attributes to built-in types.");

PyDoc_STRVAR(monkeypatch__doc__, "Patch built-in types with custom attributes.");
static PyObject *monkeypatch(PyObject *self, PyObject *args, PyObject *kwargs) {
    PyObject *target;
    PyObject *attr_name;
    PyObject *attr_val;

    char *kwlist[] = {"target", "name", "value", NULL};

    if(!PyArg_ParseTupleAndKeywords(args, kwargs, "OOO", kwlist, &target, &attr_name, &attr_val))
        return NULL;

    _PyObject_GenericSetAttrWithDict(target, attr_name, attr_val, NULL);

    Py_RETURN_NONE;
}

struct PyMethodDef methods[] = {
    {"monkeypatch", monkeypatch, METH_VARARGS | METH_KEYWORDS, monkeypatch__doc__},
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
