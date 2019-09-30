#pragma once
#include <algorithm>

#include "span.h"
#include "json.h"

#include "activation_function.h"
#include "layer_type.h"

namespace blackbox
{
    class output_layer : public layer_type
    {
    public:
        output_layer(size_t width,
                     activation_function activation)
            : layer_type(width, width)
            , m_activation(activation)
        {
        }

        activation_function get_activation_function()
        {
            return m_activation;
        }

        std::string get_type_name()
        {
            return "output_layer";
        }

        void compute(std::span<const float> signals_in,
                     std::span<float> signals_out) const override
        {
            return std::transform(signals_in.begin(), signals_in.end(), signals_out.begin(), m_activation);
        }

    private:
        activation_function m_activation;
    };

    template<>
    struct layer_serializer<output_layer>
    {

    };
}
