#include <LightGBDT/tree_learner.h>

#include "serial_tree_learner.h"

namespace LightGBDT {

TreeLearner* TreeLearner::CreateTreeLearner(const std::string& learner_type, const std::string& device_type, const TreeConfig* tree_config) {
  if (device_type == std::string("cpu")) {
    if (learner_type == std::string("serial")) {
      return new SerialTreeLearner(tree_config);
    } 
  }
  return nullptr;
}

}  // namespace LightGBDT