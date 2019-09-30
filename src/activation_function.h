#pragma once
#include <functional>

namespace blackbox
{
    struct activation_function
    {
        using callback_type = std::function<float(float)>;

        callback_type activation;
        callback_type derivative;

        float operator()(float x) const
        {
            return activation(x);
        }
    };
}
