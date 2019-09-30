#pragma once
#include "span.h"

namespace blackbox
{
    class layer
    {
    public:
        layer(int width,
              int output_width) noexcept
            : m_width(width)
            , m_output_width(output_width)
        {
        }

        int width() const noexcept
        {
            return m_width;
        }

        int output_width() const noexcept
        {
            return m_output_width;
        }
        
        virtual void compute(std::span<const float> signals_in,
                             std::span<float> signals_out) const = 0;

    private:
        int m_width;
        int m_output_width;
    };
}
