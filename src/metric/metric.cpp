#include <LightGBDT/metric.h>
#include "multiclass_metric.hpp"

namespace LightGBDT {

Metric* Metric::CreateMetric(const std::string& type, const MetricConfig& config) {
    return new MultiSoftmaxLoglossMetric(config);
}

}  // namespace LightGBM