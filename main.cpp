#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;

int getnumber(const char *askfor);

const int defaultpxmax = 15;

int main(int argc, char *argv[]){
    sf::Image imgtex;
    int width, height, pxmax = defaultpxmax, pixelcount = 0;
    string imgToOpen = "ref.png";
    if(argc > 1)
        imgToOpen = string(argv[1]);
    if(!imgtex.loadFromFile(imgToOpen))
        return -1;
    width = imgtex.getSize().x;
    height = imgtex.getSize().y;
    if(argc > 2){
        try{
            pxmax = stoi(argv[2]);
        }
        catch(invalid_argument){
            cout << "invalid arguments, enter a number for 2nd paramter\n";
            return -1;
        }
    }
    pxmax = (width*height) * pxmax/100;
    srand(clock());
    sf::Color pxcolor;
    sf::Vector2 pxpos(0, 0);
    
    while (pixelcount < pxmax){
        if(pixelcount < pxmax/4){
            pxcolor = sf::Color::Red;
        }
        else if(pixelcount < pxmax/2){
            pxcolor = sf::Color::Green;
        }
        else if(pixelcount < (pxmax/4)*3){
            pxcolor = sf::Color::Blue;
        }
        else{
            pxcolor = sf::Color::Magenta;
        }
        int spawncorner = random()%4;
        switch (spawncorner){
        case 0:
            pxpos = sf::Vector2((int)(random()%width), 0); 
            break;
        case 1:
            pxpos = sf::Vector2(width-1, (int)(random()%height));
            break;
        case 2:
            pxpos = sf::Vector2((int)(random()%width), height-1);
            break;
        case 3:
            pxpos = sf::Vector2(0, (int)(random()%height));
            break;
        }
        while (true){
            if(pxpos.x > 0 && imgtex.getPixel(pxpos.x-1, pxpos.y) != sf::Color::Black
            || pxpos.x < width-1 && imgtex.getPixel(pxpos.x+1, pxpos.y) != sf::Color::Black

            ||pxpos.y > 0 && imgtex.getPixel(pxpos.x, pxpos.y-1) != sf::Color::Black
            ||pxpos.y < height-1 && imgtex.getPixel(pxpos.x, pxpos.y+1) != sf::Color::Black
            ){
                imgtex.setPixel(pxpos.x, pxpos.y, pxcolor);
                pixelcount++;
                cout << "hit x: " << pxpos.x << " y: " << pxpos.y << endl << pxmax-pixelcount << " pixels to go (" << pixelcount/(float)(pxmax)*100 <<"%)" << endl;
                break;
            }
            int rnum = random()%4;
            if(rnum == 0 && pxpos.x != 0){
                pxpos.x--;
                continue;
            }
            if(rnum == 1 && pxpos.x < width-1){
                pxpos.x++;
                continue;
            }
            if(rnum == 2 && pxpos.y != 0){
                pxpos.y--;
                continue;
            }
            if(rnum == 3 && pxpos.y < height-1){
                pxpos.y++;
            }
        }
        
    }
    imgtex.saveToFile("result.png");
}