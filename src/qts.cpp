#include "qts.h"

#include <RcppEigen.h>

Rcpp::DataFrame qts2angle(const Rcpp::DataFrame &qts,
                          const bool disable_normalization)
{
  unsigned int nSamples = qts.nrows();
  Eigen::Quaterniond qValue;
  Eigen::VectorXd resValue(nSamples);
  Rcpp::NumericVector wValues = qts["w"];
  Rcpp::NumericVector xValues = qts["x"];
  Rcpp::NumericVector yValues = qts["y"];
  Rcpp::NumericVector zValues = qts["z"];

  Eigen::Quaterniond refValue;
  refValue.w() = wValues(0);
  refValue.x() = xValues(0);
  refValue.y() = yValues(0);
  refValue.z() = zValues(0);
  if (!disable_normalization)
    refValue.normalize();

  for (unsigned int i = 0;i < nSamples;++i)
  {
    qValue.w() = wValues(i);
    qValue.x() = xValues(i);
    qValue.y() = yValues(i);
    qValue.z() = zValues(i);
    if (!disable_normalization)
      qValue.normalize();

    resValue(i) = qValue.angularDistance(refValue);
  }

  Rcpp::DataFrame dfValue = Rcpp::DataFrame::create(
    Rcpp::Named("time") = qts["time"],
    Rcpp::Named("angle") = Rcpp::wrap(resValue)
  );

  dfValue.attr("class") = Rcpp::CharacterVector::create("tbl_df", "tbl", "data.frame");

  return dfValue;
}

Rcpp::DataFrame reorient_qts(const Rcpp::DataFrame &qts,
                             const bool disable_normalization)
{
  unsigned int nSamples = qts.nrows();
  Eigen::Quaterniond qValue;
  Rcpp::DataFrame resValue = Rcpp::clone(qts);
  Rcpp::NumericVector wValues = resValue["w"];
  Rcpp::NumericVector xValues = resValue["x"];
  Rcpp::NumericVector yValues = resValue["y"];
  Rcpp::NumericVector zValues = resValue["z"];

  Eigen::Quaterniond refValue;
  refValue.w() = wValues(0);
  refValue.x() = xValues(0);
  refValue.y() = yValues(0);
  refValue.z() = zValues(0);
  if (!disable_normalization)
    refValue.normalize();
  refValue = refValue.inverse();

  for (unsigned int i = 0;i < nSamples;++i)
  {
    qValue.w() = wValues(i);
    qValue.x() = xValues(i);
    qValue.y() = yValues(i);
    qValue.z() = zValues(i);
    if (!disable_normalization)
      qValue.normalize();

    qValue = refValue * qValue;

    wValues(i) = qValue.w();
    xValues(i) = qValue.x();
    yValues(i) = qValue.y();
    zValues(i) = qValue.z();
  }

  return resValue;
}

Rcpp::DataFrame normalize_qts(const Rcpp::DataFrame &qts)
{
  unsigned int nGrid = qts.nrows();
  Rcpp::DataFrame outValue = Rcpp::clone(qts);
  Rcpp::NumericVector wValues = outValue["w"];
  Rcpp::NumericVector xValues = outValue["x"];
  Rcpp::NumericVector yValues = outValue["y"];
  Rcpp::NumericVector zValues = outValue["z"];
  Eigen::Quaterniond qValue;

  for (unsigned int i = 0;i < nGrid;++i)
  {
    qValue.w() = wValues(i);
    qValue.x() = xValues(i);
    qValue.y() = yValues(i);
    qValue.z() = zValues(i);
    qValue.normalize();
    wValues(i) = qValue.w();
    xValues(i) = qValue.x();
    yValues(i) = qValue.y();
    zValues(i) = qValue.z();
  }

  return outValue;
}
