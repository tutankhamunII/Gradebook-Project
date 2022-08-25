////////Developed by William Moon, Used with the concsent of the developer
#ifndef COLOR_h
#define COLOR_h
#include <string>
#include <vector>
class Color
{
public:
    enum name
    {
        black,
        red,
        green,
        yellow,
        blue,
        purple,
        cyan,
        white
    };
    Color(const std::string &, name, int, int);

    static std::string setFg(name);
    static std::string setBg(name);
    static std::string setColor(name, name);
    static std::string reset();
    static void test();

private:
    static const Color &getByName(name);
    name getName() const { return m_name; };
    const std::string &getNameStr() const { return m_name_str; };
    int getFgCode() const { return m_fg; };
    int getBgCode() const { return m_bg; };
    std::string m_name_str;
    name m_name;
    int m_fg;
    int m_bg;
    static const std::string escape;
    static const std::vector<Color> colormap;

private:
};
#endif