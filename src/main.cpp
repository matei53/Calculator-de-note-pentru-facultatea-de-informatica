#include "Aplicatie.h"
#include "Materie.h"
#include <fstream>

int main()
{
    std::ifstream f("..\\..\\..\\..\\src\\materii.txt");
    std::vector<Materie> materii;
    std::string line;
    while (getline(f, line))
    {
        std::string materie = line;
        getline(f, line); int credit = std::stoi(line.substr(line.find_last_of(" ")));
        getline(f, line); int an = std::stoi(line.substr(line.find_last_of(" ")));
        getline(f, line); bool optional = std::stoi(line.substr(line.find_last_of(" ")));
        getline(f, line); bool facultativ = std::stoi(line.substr(line.find_last_of(" ")));
        std::vector<Notare> notari;
        getline(f, line);
        for (int i = 1; i <= 3; i++)
        {
            float nota_finala = std::stof(line.substr(line.find_last_of(" ")));
            std::vector<Evaluare> evaluari;
            while (getline(f, line) && line.find("nota_finala") == std::string::npos && line != "-")
            {
                std::string tip = line;
                getline(f, line); float parte_din_final = std::stof(line.substr(line.find_last_of(" ")));
                getline(f, line); float punctaj_maxim = std::stof(line.substr(line.find_last_of(" ")));
                getline(f, line); int prag = std::stoi(line.substr(line.find_last_of(" ")));
                getline(f, line); float nota = std::stof(line.substr(line.find_last_of(" ")));
                evaluari.push_back(Evaluare(tip, parte_din_final, punctaj_maxim, prag, nota));
            }
            notari.push_back(Notare(evaluari, nota_finala));
        }
        materii.push_back(Materie(materie, credit, notari, an, optional, facultativ));
    }

    f.close();

    Aplicatie app("Calculator note", 1900, 980);

    sf::Font font("..\\..\\..\\..\\src\\Roboto-Black.ttf"); //try

    auto titlu = std::make_shared<TitleText>(TitleText({ 0, 0 }, { 1900, 135 }, 80, "Welcome", font,
        sf::Color::Yellow, sf::Color::Red, sf::Color::Green, sf::Color::Blue));
    app.addObject(titlu);
    titlu->animateColors();
    titlu->align();

    auto alegere_serie = std::make_shared<TitleText>(TitleText({ 0, 155 }, { 380, 85 }, 50, "Alegeti seria", font, sf::Color::Yellow));
    app.addObject(alegere_serie);
    alegere_serie->align();

    std::vector<std::shared_ptr<Buton>> butoane_serii;
    butoane_serii.push_back(std::make_shared<Buton>(Buton({ 400, 155 }, { 85, 85 }, 50, "13", font, sf::Color::Green, sf::Color::Yellow)));
    butoane_serii.push_back(std::make_shared<Buton>(Buton({ 500, 155 }, { 85, 85 }, 50, "14", font, sf::Color::Green, sf::Color::Yellow)));
    butoane_serii.push_back(std::make_shared<Buton>(Buton({ 600, 155 }, { 85, 85 }, 50, "15", font, sf::Color::Green, sf::Color::Yellow)));
    butoane_serii.push_back(std::make_shared<Buton>(Buton({ 700, 155 }, { 85, 85 }, 50, "23", font, sf::Color::Green, sf::Color::Yellow)));
    butoane_serii.push_back(std::make_shared<Buton>(Buton({ 800, 155 }, { 85, 85 }, 50, "24", font, sf::Color::Green, sf::Color::Yellow)));
    butoane_serii.push_back(std::make_shared<Buton>(Buton({ 900, 155 }, { 85, 85 }, 50, "25", font, sf::Color::Green, sf::Color::Yellow)));
    butoane_serii.push_back(std::make_shared<Buton>(Buton({ 1000, 155 }, { 85, 85 }, 50, "33", font, sf::Color::Green, sf::Color::Yellow)));
    butoane_serii.push_back(std::make_shared<Buton>(Buton({ 1100, 155 }, { 85, 85 }, 50, "34", font, sf::Color::Green, sf::Color::Yellow)));
    butoane_serii.push_back(std::make_shared<Buton>(Buton({ 1200, 155 }, { 85, 85 }, 50, "35", font, sf::Color::Green, sf::Color::Yellow)));
    for (std::shared_ptr<Buton> b : butoane_serii)
    {
        b->align();
        b->setClickable(1);
        app.addObject(b);
    }

    std::shared_ptr<Buton> buton_inainte;
    std::shared_ptr<TitleText> titlu_facultative;
    std::shared_ptr<TitleText> titlu_optionale;
    std::vector<std::shared_ptr<Buton>> butoane_optionale;
    std::vector<std::shared_ptr<Buton>> butoane_facultative;
    int an = 0, serie = 0;
    std::vector<Materie> optionale_selectate;
    std::vector<Materie> facultative_selectate;

    struct NoteMaterie
    {
        std::shared_ptr<TitleText> titlu_materie;
        std::shared_ptr<TitleText> nota_finala;
        std::vector<std::shared_ptr<TitleText>> metode_evaluare;
        std::vector<std::shared_ptr<TextInput>> inputuri;
        std::vector<std::shared_ptr<Buton>> salvari;
    };
    std::vector<NoteMaterie> notare_materii;

    std::shared_ptr<TextInput> input_activ;
    std::shared_ptr<TitleText> titlu_medie_finala_bursa;
    std::shared_ptr<TitleText> titlu_medie_finala_buget;
    std::shared_ptr<TitleText> medie_finala_bursa;
    std::shared_ptr<TitleText> medie_finala_buget;

    while (app.isRunning())
    {
        app.update();
        app.render();

        if (app.getClick())
        {
            if (std::find(butoane_serii.begin(), butoane_serii.end(), app.getClick()) != butoane_serii.end())
            {
                for (std::shared_ptr<Buton> b : butoane_serii)
                {
                    b->setClickable(0);
                    app.removeClickableObject(b);
                }
                auto b = std::dynamic_pointer_cast<Buton>(app.getClick());
                b->animateClick();
                app.setClick(nullptr);

                buton_inainte = std::make_shared<Buton>(Buton({ 1300, 155 }, { 185, 85 }, 50, "Inainte", font, sf::Color::Magenta, sf::Color::Red));
                buton_inainte->setClickable(1);
                buton_inainte->align();
                app.addObject(buton_inainte);

                an = b->getText().front() - '0';
                serie = b->getText().back() - '0';

                if (an == 1)
                {
                    titlu_facultative = std::make_shared<TitleText>(TitleText({ 0, 250 }, { 600, 75 }, 40, "Alegeti facultativele", font, sf::Color::Yellow));
                    app.addObject(titlu_facultative);
                    titlu_facultative->align();

                    float y_fac = 330;
                    for (Materie m : materii)
                    {
                        if (m.getAn() == an && m.isFacultativ())
                        {
                            butoane_facultative.push_back(std::make_shared<Buton>(Buton({ 0, y_fac }, { 500, 70 }, 30, m.getNume(), font, sf::Color::Green, sf::Color::Yellow)));
                            y_fac += 75;
                        }
                    }
                    for (std::shared_ptr<Buton> b : butoane_facultative)
                    {
                        b->align();
                        b->setClickable(1);
                        app.addObject(b);
                    }
                }
                else if (an == 2)
                {
                    titlu_facultative = std::make_shared<TitleText>(TitleText({ 0, 250 }, { 600, 75 }, 40, "Alegeti facultativele", font, sf::Color::Yellow));
                    app.addObject(titlu_facultative);
                    titlu_facultative->align();

                    float y = 330;
                    for (Materie m : materii)
                    {
                        if (m.getAn() == an && m.isFacultativ())
                        {
                            butoane_facultative.push_back(std::make_shared<Buton>(Buton({ 0, y }, { 500, 70 }, 30, m.getNume(), font, sf::Color::Green, sf::Color::Yellow)));
                            y += 75;
                        }
                    }
                    for (std::shared_ptr<Buton> b : butoane_facultative)
                    {
                        b->align();
                        b->setClickable(1);
                        app.addObject(b);
                    }

                    titlu_optionale = std::make_shared<TitleText>(TitleText({ 0, y }, { 600, 75 }, 40, "Alegeti optionalele", font, sf::Color::Yellow));
                    app.addObject(titlu_optionale);
                    titlu_optionale->align();
                    y += 80;

                    for (Materie m : materii)
                    {
                        if (m.getAn() == an && m.isOptional())
                        {
                            butoane_optionale.push_back(std::make_shared<Buton>(Buton({ 0, y }, { 500, 70 }, 30, m.getNume(), font, sf::Color::Green, sf::Color::Yellow)));
                            y += 75;
                        }
                    }
                    for (std::shared_ptr<Buton> b : butoane_optionale)
                    {
                        b->align();
                        b->setClickable(1);
                        app.addObject(b);
                    }
                }
                else if (an == 3)
                {
                    titlu_optionale = std::make_shared<TitleText>(TitleText({ 0, 250 }, { 600, 75 }, 40, "Alegeti optionalele", font, sf::Color::Yellow));
                    app.addObject(titlu_optionale);
                    titlu_optionale->align();

                    float x_opt = 0, y_opt = 330;
                    for (Materie m : materii)
                    {
                        if (m.getAn() == an && m.isOptional())
                        {
                            butoane_optionale.push_back(std::make_shared<Buton>(Buton({ x_opt, y_opt }, { 400, 40 }, 25, m.getNume(), font, sf::Color::Green, sf::Color::Yellow)));
                            y_opt += 45;
                            if (y_opt > 950 || butoane_optionale.size() == 23)
                            {
                                x_opt += 425;
                                y_opt = 330;
                            }
                        }
                    }
                    for (std::shared_ptr<Buton> b : butoane_optionale)
                    {
                        b->align();
                        b->setClickable(1);
                        app.addObject(b);
                    }
                }
            }

            else if (std::find(butoane_optionale.begin(), butoane_optionale.end(), app.getClick()) != butoane_optionale.end())
            {
                if (an == 2)
                {
                    for (std::shared_ptr<Buton> b : butoane_optionale)
                    {
                        b->setClickable(0);
                        app.removeClickableObject(b);
                    }
                    auto b = std::dynamic_pointer_cast<Buton>(app.getClick());
                    b->changeColor(sf::Color::Cyan);
                    for (Materie m : materii)
                    {
                        if (m.getNume() == b->getText())
                        {
                            optionale_selectate.push_back(m);
                            break;
                        }
                    }
                }
                else if (an == 3)
                {
                    auto b = std::dynamic_pointer_cast<Buton>(app.getClick());
                    b->changeColor(sf::Color::Cyan);
                    b->setClickable(0);
                    app.removeClickableObject(b);

                    int n = 0;
                    while (b != butoane_optionale.at(n)) n++;
                    if (n <= 23)
                    {
                        int nr = 0;
                        for (int i = 0; i <= 23; i++)
                            if (!butoane_optionale.at(i)->isClickable())
                                nr++;
                        if (nr == 3)
                        {
                            for (int i = 0; i <= 23; i++)
                            {
                                butoane_optionale.at(i)->setClickable(0);
                                app.removeClickableObject(butoane_optionale.at(i));
                            }
                        }
                    }
                    else
                    {
                        int nr = 0;
                        for (int i = 24; i <= 41; i++)
                            if (!butoane_optionale.at(i)->isClickable())
                                nr++;
                        if (nr == 3)
                        {
                            for (int i = 23; i <= 41; i++)
                            {
                                butoane_optionale.at(i)->setClickable(0);
                                app.removeClickableObject(butoane_optionale.at(i));
                            }
                        }
                    }
                    for (Materie m : materii)
                    {
                        if (m.getNume() == b->getText())
                        {
                            optionale_selectate.push_back(m);
                            break;
                        }
                    }
                }
                app.setClick(nullptr);
            }
            else if (std::find(butoane_facultative.begin(), butoane_facultative.end(), app.getClick()) != butoane_facultative.end())
            {
                auto b = std::dynamic_pointer_cast<Buton>(app.getClick());
                b->changeColor(sf::Color::Cyan);
                b->setClickable(0);
                app.removeClickableObject(b);
                app.setClick(nullptr);

                for (Materie m : materii)
                {
                    if (m.getNume() == b->getText())
                    {
                        facultative_selectate.push_back(m);
                        break;
                    }
                }
            }

            else if (app.getClick() == buton_inainte)
            {
                app.setClick(nullptr);
                bool ok = 1;
                for (std::shared_ptr<Buton> b : butoane_optionale)
                    if (b->isClickable())
                    {
                        ok = 0;
                        break;
                    }
                if (ok == 1)
                {
                    app.removeObject(titlu);
                    app.removeObject(alegere_serie);
                    app.removeObject(buton_inainte);
                    app.removeObject(alegere_serie);
                    app.removeObject(titlu_facultative);
                    app.removeObject(titlu_optionale);
                    for (std::shared_ptr<Buton> b : butoane_serii) app.removeObject(b);
                    for (std::shared_ptr<Buton> b : butoane_optionale) app.removeObject(b);
                    for (std::shared_ptr<Buton> b : butoane_facultative) app.removeObject(b);

                    titlu_medie_finala_bursa = std::make_shared<TitleText>(TitleText({ 1700, 5 }, { 155, 35 }, 20, "MEDIE BURSA", font, sf::Color::Magenta));
                    medie_finala_bursa = std::make_shared<TitleText>(TitleText({ 1700, 40 }, { 155, 85 }, 50, "", font, sf::Color::Yellow));
                    titlu_medie_finala_buget = std::make_shared<TitleText>(TitleText({ 1700, 150 }, { 155, 35 }, 20, "MEDIE BUGET", font, sf::Color::Magenta));
                    medie_finala_buget = std::make_shared<TitleText>(TitleText({ 1700, 185 }, { 155, 85 }, 50, "", font, sf::Color::Yellow));
                    titlu_medie_finala_bursa->align();
                    titlu_medie_finala_buget->align();
                    app.addObject(titlu_medie_finala_bursa);
                    app.addObject(titlu_medie_finala_buget);
                    app.addObject(medie_finala_bursa);
                    app.addObject(medie_finala_buget);

                    float x = 5, y = 5;
                    for (Materie m : materii)
                    {
                        if (m.getAn() == an)
                        {
                            if ((m.isOptional() && (std::find(optionale_selectate.begin(), optionale_selectate.end(), m) != optionale_selectate.end()) ||
                                (m.isFacultativ() && std::find(facultative_selectate.begin(), facultative_selectate.end(), m) != facultative_selectate.end()) ||
                                (!m.isOptional() && !m.isFacultativ())))
                            {
                                if (notare_materii.size() == 6)
                                {
                                    x = 5; y = 325;
                                }
                                else if (notare_materii.size() == 12)
                                {
                                    x = 5; y = 645;
                                }
                                float y1 = y;
                                NoteMaterie M;
                                M.titlu_materie = std::make_shared<TitleText>(TitleText({ x, y1 }, { 275, 35 }, 15, m.getNume(), font, sf::Color::Green));
                                M.titlu_materie->align();
                                app.addObject(M.titlu_materie);
                                for (Evaluare e : m.getNotare(serie).getEvals())
                                {
                                    y1 += 35;
                                    auto ev = std::make_shared<TitleText>(TitleText({ x, y1 }, { 155, 35 }, 15, e.getTip(), font, sf::Color::Green));
                                    auto inp = std::make_shared<TextInput>(TextInput({ x + 160, y1 }, { 75, 35 }, 15, "", font, sf::Color::Green, 4));
                                    auto save = std::make_shared<Buton>(Buton({ x + 240, y1 }, { 35, 35 }, 15, "OK", font, sf::Color::Green, sf::Color::Red));
                                    ev->align(); inp->align(); save->align();
                                    inp->setClickable(1);
                                    save->setClickable(1);
                                    M.metode_evaluare.push_back(ev);
                                    M.inputuri.push_back(inp);
                                    M.salvari.push_back(save);
                                    app.addObject(M.metode_evaluare.back());
                                    app.addObject(M.inputuri.back());
                                    app.addObject(M.salvari.back());
                                }
                                notare_materii.push_back(M);
                            }
                        }
                        x += 280;
                    }
                }
            }
        }
    }

    return 0;
}