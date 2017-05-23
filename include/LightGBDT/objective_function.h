#ifndef LIGHTGBDT_OBJECTIVE_FUNCTION_H_
#define LIGHTGBDT_OBJECTIVE_FUNCTION_H_

#include <LightGBDT/meta.h>
#include <LightGBDT/config.h>
#include <LightGBDT/dataset.h>
#include <functional>

namespace LightGBDT {
/*!
* \brief The interface of Objective Function.
*/
class ObjectiveFunction {
public:
  /*! \brief virtual destructor */
  virtual ~ObjectiveFunction() {}

  /*!
  * \brief Initialize
  * \param metadata Label data
  * \param num_data Number of data
  */
  virtual void Init(const Metadata& metadata, data_size_t num_data) = 0;

  /*!
  * \brief calculating first order derivative of loss function
  * \param score prediction score in this round
  * \gradients Output gradients
  * \hessians Output hessians
  */
  virtual void GetGradients(const double* score,
    score_t* gradients, score_t* hessians) const = 0;

  virtual const char* GetName() const = 0;

  virtual bool IsConstantHessian() const { return false; }

  virtual bool BoostFromAverage() const { return false; }

  virtual bool SkipEmptyClass() const { return false; }

  virtual int NumTreePerIteration() const { return 1; }

  virtual int NumPredictOneRow() const { return 1; }

  virtual void ConvertOutput(const double* input, double* output) const {
    output[0] = input[0];
  }

  virtual std::string ToString() const = 0;

  ObjectiveFunction() = default;
  /*! \brief Disable copy */
  ObjectiveFunction& operator=(const ObjectiveFunction&) = delete;
  /*! \brief Disable copy */
  ObjectiveFunction(const ObjectiveFunction&) = delete;

  /*!
  * \brief Create object of objective function
  * \param type Specific type of objective function
  * \param config Config for objective function
  */
  LIGHTGBDT_EXPORT static ObjectiveFunction* CreateObjectiveFunction(const std::string& type,
    const ObjectiveConfig& config);

  /*!
  * \brief Load objective function from string object
  */
  LIGHTGBDT_EXPORT static ObjectiveFunction* CreateObjectiveFunction(const std::string& str);
};

}  // namespace LightGBDT

#endif   // LightGBDT_OBJECTIVE_FUNCTION_H_