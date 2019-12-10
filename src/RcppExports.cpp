// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// GetCostMatrix
Rcpp::NumericMatrix GetCostMatrix(const Rcpp::NumericMatrix& x, const Rcpp::NumericMatrix& y);
RcppExport SEXP _squad_GetCostMatrix(SEXP xSEXP, SEXP ySEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Rcpp::NumericMatrix& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const Rcpp::NumericMatrix& >::type y(ySEXP);
    rcpp_result_gen = Rcpp::wrap(GetCostMatrix(x, y));
    return rcpp_result_gen;
END_RCPP
}
// GetSquaredL2Distance
double GetSquaredL2Distance(const Rcpp::NumericMatrix& x, const Rcpp::NumericMatrix& y);
RcppExport SEXP _squad_GetSquaredL2Distance(SEXP xSEXP, SEXP ySEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Rcpp::NumericMatrix& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const Rcpp::NumericMatrix& >::type y(ySEXP);
    rcpp_result_gen = Rcpp::wrap(GetSquaredL2Distance(x, y));
    return rcpp_result_gen;
END_RCPP
}
// slerp
Rcpp::NumericVector slerp(const Rcpp::NumericVector& v0, const Rcpp::NumericVector& v1, const double t);
RcppExport SEXP _squad_slerp(SEXP v0SEXP, SEXP v1SEXP, SEXP tSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type v0(v0SEXP);
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type v1(v1SEXP);
    Rcpp::traits::input_parameter< const double >::type t(tSEXP);
    rcpp_result_gen = Rcpp::wrap(slerp(v0, v1, t));
    return rcpp_result_gen;
END_RCPP
}
// RegularizeGrid
Rcpp::NumericMatrix RegularizeGrid(const Rcpp::NumericVector& x, const Rcpp::NumericMatrix& y, const unsigned int outSize);
RcppExport SEXP _squad_RegularizeGrid(SEXP xSEXP, SEXP ySEXP, SEXP outSizeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const Rcpp::NumericMatrix& >::type y(ySEXP);
    Rcpp::traits::input_parameter< const unsigned int >::type outSize(outSizeSEXP);
    rcpp_result_gen = Rcpp::wrap(RegularizeGrid(x, y, outSize));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_squad_GetCostMatrix", (DL_FUNC) &_squad_GetCostMatrix, 2},
    {"_squad_GetSquaredL2Distance", (DL_FUNC) &_squad_GetSquaredL2Distance, 2},
    {"_squad_slerp", (DL_FUNC) &_squad_slerp, 3},
    {"_squad_RegularizeGrid", (DL_FUNC) &_squad_RegularizeGrid, 3},
    {NULL, NULL, 0}
};

RcppExport void R_init_squad(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
