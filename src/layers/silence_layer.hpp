#ifndef CAFFE_SILENCE_LAYER_HPP_
#define CAFFE_SILENCE_LAYER_HPP_

#include <vector>

#include "../layer.hpp"
#include "../proto/caffe.pb.h"

namespace caffe {

/**
 * @brief Ignores bottom blobs while producing no top blobs. (This is useful
 *        to suppress outputs during testing.)
 */
template <typename Dtype>
class SilenceLayer : public Layer<Dtype> {
 public:
  explicit SilenceLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}

  virtual inline const char* type() const { return "Silence"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 0; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
};

}  // namespace caffe

#endif  // CAFFE_SILENCE_LAYER_HPP_