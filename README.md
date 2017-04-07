# DDS Python API

## Overview
**dds-python** is a simple Python API for Vortex Lite (soon also for OpenSplice).

This API supports:

- **IDL-based Topic Types**. In this case the equivalent python type 
  has to be defined using the appropropriate ctype structure.
  
- **Python Objects**. Python objects can be used as Topic types, in this
  case the wire representaiton is that of flexy-types, meaning a 
  key/value pair.
  
Regardless of the kinds of type definition interoperability and instance management are maintained (see code examples).

## Installation
**dds-python** depends on:

- [**jsonpikle**](https://github.com/jsonpickle/jsonpickle), please refer to the project page for installation informations.

- [**Vortex Lite**](http://www.prismtech.com), refer to the installation instructions to see how to get it set up.

Once the dependencies are intalled simply do:

	$ cd dds-python/builtin-types
	$ make

To test your installation do:

	$ cd dds-python
	$ python test_reader.py &
	$ python test_writer.py 
	

Equivalently you can test the flexy types by:

	$ cd dds-python
	$ python test_flexy_reader.py &
	$ python test_flexy_writer.py 





 
