#include <torch/extension.h>

#define CHECK_CUDA(x) TORCH_CHECK(x.is_cuda(), #x " must be a CUDA tensor")
#define CHECK_CONTIGUOUS(x) TORCH_CHECK(x.is_contiguous(), #x " must be contiguous")
#define CHECK_INPUT(x) CHECK_CUDA(x); CHECK_CONTIGUOUS(x)  

torch::Tensor blockdiag_matmul_fw_cu(
    const torch::Tensor x,
    const torch::Tensor LR
);

torch::Tensor blockdiag_matmul_bw_cu(
    const torch::Tensor dL_dout,
    const torch::Tensor x,
    const   torch::Tensor LR
);

