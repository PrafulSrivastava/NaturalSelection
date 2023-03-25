#ifndef GENE_POOL_HPP
#define GENE_POOL_HPP

#include "CommonTypes.hpp"

namespace NaturalSelection::Brain
{

    class GenePool
    {
    private:
        std::unordered_map<Common::GenomeSequence, float> m_probabilities;
        float m_sum{0.0f};

    public:
        GenePool()
        {
            // GeneratePatterns({}, Common::GenomeSequenceLength);
            m_probabilities = {{"10000", 1.0f}, {"10000", 1.0f}, {"01000", 1.0f}, {"00100", 1.0f}, {"00010", 1.0f}};

            Init();
        }

        void Init()
        {
            m_sum = 0;
            for (auto seq : m_probabilities)
            {
                Log(Log::INFO, seq.first, ", ", seq.second);
            }

            for (auto &it : m_probabilities)
            {
                m_sum += it.second;
            }

            Log(Log::INFO, "*************************************", m_sum);
        }

        void GeneratePatterns(Common::GenomeSequence prefix, int length)
        {
            if (prefix.length() == length)
            {
                m_probabilities[prefix] = 1.0f;
                return;
            }
            GeneratePatterns(prefix + "0", length);
            GeneratePatterns(prefix + "1", length);
        }

        Common::GenomeSequence GetGenomeSequence()
        {
            // Log(Log::INFO, __func__);

            float random = std::fmod(rand(), m_sum) * 100;
            // Log(Log::INFO, __func__, "random", random);

            float sum = 0;
            Common::GenomeSequence seq{};
            for (auto &it : m_probabilities)
            {
                // Log(Log::INFO, __func__, "sum", sum);

                sum += it.second * 100;
                seq = it.first;
                if (sum > random)
                {
                    break;
                }
            }
            return seq;
        }

        void resetProbability(std::unordered_map<Common::GenomeSequence, float> mpOfSequences)
        {
            m_probabilities.clear();
            int sum{0};
            for (auto it : mpOfSequences)
            {
                // Log(Log::INFO, "Map of cnt: ", it.first, ", ", it.second);
                sum += it.second;
            }
            for (auto it : mpOfSequences)
            {
                m_probabilities[it.first] = it.second / sum;
            }
            Init();
        }
    };

}

#endif