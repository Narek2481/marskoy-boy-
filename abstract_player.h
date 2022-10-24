
class abstract_player{
public:
    abstract_player();
    // virtual void shooting_at_coordinates();
    void generate_ship_coordinates(int size);
    void map_screen();
private:
    int ships[10][10];
    bool shot_places [10][10];
    void generate_ship_coordinates_quarters(int x ,int y,int ships[][10]);
    void generate_ship_coordinates_thirds(int x,int y,int ships[][10]);
    void generate_ship_coordinates_second(int x,int y,int ships[][10]);
    void circle_close(int x, int y);
};
