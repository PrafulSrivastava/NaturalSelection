#ifndef QUAD_TREE
#define QUAD_TREE

#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>

namespace NaturalSelection::Manager
{
    constexpr auto Capacity = 4;
    constexpr auto Quadrants = 4;

    enum class SpaceType : int8_t
    {
        Invalid = -1,
        NW = 0,
        NE,
        SW,
        SE
    };

    static SpaceType FindQuad(const sf::Vector2f &coorRoot, const sf::Vector2f &coorNewNode)
    {
        if (coorRoot.x <= coorNewNode.x)
        {
            if (coorRoot.y <= coorNewNode.y)
            {
                return SpaceType::SE;
            }
            else
            {
                return SpaceType::NE;
            }
        }
        else
        {
            if (coorRoot.y <= coorNewNode.y)
            {
                return SpaceType::SW;
            }
            else
            {
                return SpaceType::NW;
            }
        }
    }

    template <typename Unit>
    struct Node
    {
        Node(sf::Vector2f coor, sf::Vector2f size)
        {
            visionBox.setPosition(coor);
            visionBox.setOutlineColor(sf::Color::Red);
            visionBox.setFillColor(sf::Color::Black);
            visionBox.setOutlineThickness(5);
            visionBox.setSize(size);

            Common::Utility::SetOriginToCenter(visionBox);
        }

        ~Node()
        {
            points.clear();
            for (int i = 0; i < childNodes.size(); i++)
            {
                childNodes[i].reset();
            }
        }

        bool isFull()
        {
            return points.size() >= Capacity;
        }

        bool isDivided()
        {
            return childNodes.size() == Quadrants;
        }

        std::vector<Unit> points;
        sf::RectangleShape visionBox;
        std::vector<std::shared_ptr<Node<Unit>>> childNodes;
    };

    template <typename Unit>
    static void Divide(std::shared_ptr<Node<Unit>> &root)
    {
        auto rect = root->visionBox.getGlobalBounds();
        auto basePos = root->visionBox.getPosition();
        auto origin = root->visionBox.getOrigin();
        auto baseSize = root->visionBox.getSize();

        // NW
        root->childNodes.push_back(
            std::make_shared<Node<Unit>>(
                sf::Vector2f(basePos.x - rect.width / 4, basePos.y - rect.height / 4),
                sf::Vector2f(baseSize.x / 2, baseSize.y / 2)));

        // NE
        root->childNodes.push_back(
            std::make_shared<Node<Unit>>(
                sf::Vector2f(basePos.x + rect.width / 4, basePos.y - rect.height / 4),
                sf::Vector2f(baseSize.x / 2, baseSize.y / 2)));

        // SW
        root->childNodes.push_back(
            std::make_shared<Node<Unit>>(
                sf::Vector2f(basePos.x - rect.width / 4, basePos.y + rect.height / 4),
                sf::Vector2f(baseSize.x / 2, baseSize.y / 2)));

        // SE
        root->childNodes.push_back(
            std::make_shared<Node<Unit>>(
                sf::Vector2f(basePos.x + rect.width / 4, basePos.y + rect.height / 4),
                sf::Vector2f(baseSize.x / 2, baseSize.y / 2)));
    }

    template <typename Unit>
    static void Insert(std::shared_ptr<Node<Unit>> &root, sf::Vector2f point, Unit val)
    {
        if (!root->visionBox.getGlobalBounds().contains(point))
        {
            return;
        }

        if (!root->isFull())
        {
            root->points.push_back(val);
        }
        else
        {
            if (!root->isDivided())
            {
                Divide<Unit>(root);
            }

            auto quad = FindQuad(root->visionBox.getPosition(), point);
            Insert<Unit>(root->childNodes[static_cast<int>(quad)], point, val);
        }
    }

    template <typename Unit>
    static void Draw(std::shared_ptr<Node<Unit>> &root, std::reference_wrapper<sf::RenderWindow> window)
    {
        std::stack<std::shared_ptr<Node<Unit>>> st;
        st.push(root);

        while (!st.empty())
        {
            auto top = st.top();
            st.pop();
            window.get().draw(top->visionBox);
            for (int i = 0; i < top->childNodes.size(); i++)
            {
                st.push(top->childNodes[i]);
            }
        }
    }

}

#endif