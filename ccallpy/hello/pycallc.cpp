#include <Python.h>

#define min(a,b)    (((a) < (b)) ? (a) : (b))

char data[1024];

void SetData(const char *str)
{
	strncpy(data, str, min(strlen(str) + 1, 1024));
}

const char *GetData()
{
	return data;
}

PyDoc_STRVAR(PySetData_doc__, "\
测试\n\
\n\
PySetData(str)\n\
str: 出入的字符串\n\
返回: \n\
null \n\
");
static PyObject* PySetData(PyObject *self, PyObject *args)
{
	const char* str = NULL;
	if ( !PyArg_ParseTuple(args, "s", &str) )
	{
		return 0;
	}
	SetData(str);
	Py_RETURN_NONE;
}

PyDoc_STRVAR(PyGetData_doc__, "\
打印数据\n\
\n\
PyGetData()\n\
返回: \n\
data \n\
");
static PyObject* PyGetData(PyObject *self, PyObject *args)
{
	const char* str = NULL;
	return PyString_FromString(GetData());
}

static PyMethodDef module_methods[] = {
	{"py_set_data", PySetData, METH_VARARGS, PySetData_doc__},
	{"py_get_data", PyGetData, METH_VARARGS, PyGetData_doc__},
	{NULL}
	};

void InitCCallPy()
{
	PyObject *module = Py_InitModule3("pycallc", module_methods,
		"python call c");
}
