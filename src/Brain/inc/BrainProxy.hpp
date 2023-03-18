#ifndef BRAIN_PROXY_HPP
#define BRAIN_PROXY_HPP

#include "IBrainProxy.hpp"
#include "Brain.hpp"

namespace NaturalSelection::Brain
{

    class BrainProxy : public IBrainProxy
    {
    public:
        BrainProxy() = default;
        ~BrainProxy() override = default;
        void React(const Common::GenomeSequence &, const Common::StimuliType &, std::reference_wrapper<sf::CircleShape>) override;

    private:
        void AddBrain(const Common::GenomeSequence &);
        std::unordered_map<Common::GenomeSequence, Brain> m_brains;
    };

}

#endif