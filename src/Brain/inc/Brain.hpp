#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "IBrain.hpp"
#include "IActionFactory.hpp"

namespace NaturalSelection::Brain
{

    class Brain : public IBrain
    {
    public:
        Brain() = default;
        Brain(const Common::GenomeSequence &);
        ~Brain() override = default;
        void React(const Common::StimuliType &, std::reference_wrapper<sf::Shape>) override;

    private:
        Common::Actions Evaluate();

        std::vector<Common::Operation> m_neurons;
    };
}

#endif