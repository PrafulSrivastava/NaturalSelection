#ifndef GRID_HPP
#define GRID_HPP

#include "PlatformHandler.hpp"
#include "CognitiveEntity.hpp"

namespace NaturalSelection::Manager
{
    constexpr auto MIN_WIDTH = 50;
    constexpr auto MIN_HEIGHT = 50;

    struct Block : sf::RectangleShape
    {
    private:
        BlockId m_id{};
        std::vector<EntityId> m_entityIds;

    public:
        Block(Position position, EntityId id) : m_id(id)
        {
            Log(Log::VERBOSE, __func__);
            this->setSize(Position(MIN_WIDTH, MIN_HEIGHT));
            this->setPosition(position);
            this->setFillColor(sf::Color::Black);
            this->setOutlineThickness(1);
            this->setOutlineColor(sf::Color::White);
        }

        void visit(EntityId id)
        {
            Log(Log::VERBOSE, __func__, id);
            m_entityIds.push_back(id);
        }

        void leave(EntityId id)
        {
            Log(Log::VERBOSE, __func__, id);
            m_entityIds.erase(std::remove(m_entityIds.begin(), m_entityIds.end(), id), m_entityIds.end());
        }

        bool inside(Position point)
        {
            Log(Log::DEBUG, __func__);
            return this->getGlobalBounds().contains(point);
        }

        std::vector<EntityId> getEntities()
        {
            Log(Log::DEBUG, __func__, "Size", m_entityIds.size());
            return m_entityIds;
        }
    };

    class Grid : public IPlatform
    {
    public:
        Grid() = default;
        Grid(const Grid &grid) = delete;
        Grid(Grid &&grid) = delete;
        Grid &operator=(const Grid &grid) = delete;
        Grid &operator=(Grid &&grid) = delete;

        ~Grid();

        void Init(const int32_t &, const int32_t &) override;
        void Register(std::reference_wrapper<Entity::CognitiveEntity<sf::CircleShape>>) override;
        void Update(const EntityId &id) override;
        std::vector<EntityId> Fetch(const EntityId &id) override;
        void Reset() override;
        void Draw(std::reference_wrapper<sf::RenderWindow>) override;

    private:
        int m_rows, m_columns;
        std::vector<Block> m_blocks;
        std::unordered_map<EntityId, BlockId> m_entity;
        std::vector<std::reference_wrapper<Entity::CognitiveEntity<sf::CircleShape>>> m_orgs;

        BlockId findBlock(const Position &);
    };

} // namespace NaturalSelection::Manager

#endif