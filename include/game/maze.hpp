
#pragma once

namespace Tank {

    #define WALL_X              40
    #define WALL_Y              40

    #define WALL_LENGHT         100
    #define WALL_THICKNESS      5

    #define WALL_WIDTH          Random::getRandomInRange(3, 15)
    #define WALL_HEIGHT         Random::getRandomInRange(3, 10)

enum directions {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Cell {
    int index; // index which change if the wall connect
    int id; // unique for each cells

    Cell *up;
    Cell *down;
    Cell *left;
    Cell *right;

    int *wall_up;
    int *wall_down;
    int *wall_left;
    int *wall_right;

    Cell(int id);

    Cell *operator[](int index);
};

class CellList {
    public:
        CellList();
        int size();
        void add(int width, int height, std::vector<int> &horizontal, std::vector<int> &vertical);
        void changeIndex(Cell *cell, int value);
        void destroyWall(int index, int wall);
        bool hasSameIndex();
        void display();
        void reset();
        ~CellList();

        Cell &operator[](int index);

    private:
        int len;
        std::vector<Cell> list;
};

class Maze {
    public:
        Maze();
        /// @brief Generate a new maze
        /// @param x Width of the maze
        /// @param y Height of the maze
        void generateNewMaze(int x, int y);
        void reset();
        void draw(sf::RenderWindow &window);
        std::list<sf::VertexArray> &getWalls();
        sf::Vector2f getSize();
        ~Maze();

    private:
        int width;
        int height;
        std::vector<int> random;
        std::vector<int> horizontal;
        std::vector<int> vertical;
        CellList cells;

        sf::VertexArray floor;
        std::list<sf::VertexArray> walls;

        void generateNewRandom();
        void generateGraphics();
        void display();
};

}
