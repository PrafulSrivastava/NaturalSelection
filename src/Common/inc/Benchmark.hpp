#ifndef BENCHMARK_HPP
#define BENCHMARK_HPP

#include "CommonTypes.hpp"

namespace NaturalSelection::Common
{
    template <typename Resolution>
    class Benchmark
    {
    public:
        Benchmark(std::string ctx = {}) : m_context(ctx)
        {
            m_start = std::chrono::steady_clock::now();
        }
        ~Benchmark()
        {
            auto duration = std::chrono::steady_clock::now() - m_start;
            auto timeElapsed = std::chrono::duration_cast<Resolution>(duration);
            // Log(Log::INFO, "Context: ", m_context, "Time Elapsed : ", timeElapsed.count());
        }

    private:
        std::chrono::time_point<std::chrono::steady_clock> m_start;
        std::string m_context{};
    };
}

#endif