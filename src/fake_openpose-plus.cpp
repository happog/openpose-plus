#include <openpose-plus.h>

class fake_uff_runner : public uff_runner
{
  public:
    void execute(const std::vector<void *> &, const std::vector<void *> &,
                 int) override
    {
    }
};

uff_runner *create_openpose_runner(const std::string &, int input_height,
                                   int input_width, int max_batch_size,
                                   bool use_f16)
{
    return new fake_uff_runner;
}

class fake_paf_processor : public paf_processor
{
  public:
    std::vector<human_t> operator()(const float *, const float *, bool) override
    {
        return std::vector<human_t>();
    }
};

paf_processor *create_paf_processor(int input_height, int input_width,
                                    int height, int width, int n_joins,
                                    int n_connections, int gauss_kernel_size)
{
    return new fake_paf_processor;
}
