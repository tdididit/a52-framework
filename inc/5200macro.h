 
.macro align

 ift :0>0

  ift (*/:1)*:1<>*
   .def ?tmp = [(*/:1)*:1+:1]-*
   :?tmp brk
  eif

 els

  ert 'Unexpected end of line'

 eif
.endm
