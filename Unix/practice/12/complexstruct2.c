// a complex number is a + bi
typedef struct complex_st {
  double real;  // real component
  double imag;  // imaginary component
} Complex, *ComplexPtr;

Complex MultiplyComplex(Complex x, Complex y) {
  Complex retval;

  retval.real = (x. real * y.real) - (x.imag * y.imag);
  retval.imag = (x. real * y.real) + (x.imag * y.imag);
  return retval;  // returns a copy of retval
}
