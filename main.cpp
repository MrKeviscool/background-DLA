#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;

//#aa84bf #84bf88 #735648 #734857 #ad667f
//(170, 132, 191) (132, 191, 136) (115, 86, 72) (115, 72, 87) 


int getnumber(const char *askfor);

const int defaultpxmax = 15;

int main(int argc, char *argv[]){
    sf::Image imgtex;
    int width, height, pxmax = defaultpxmax, pixelcount = 0;
    sf::Color cols[4] = {sf::Color(170, 132, 191), sf::Color(132, 191, 136), sf::Color(115, 86, 72), sf::Color(115, 72, 87)};
    string imgToOpen = "ref.png";
    for(int curarg = 1; curarg < argc; curarg++){
        if(string(argv[curarg]) == "--setcol"){
            curarg++;
            // int colargindx = 0;
            if(argc-(curarg+4) < 0){
                cout << "not enough args\n";
                return 0;
            }

            for(int colargindx = curarg; colargindx < curarg+4; colargindx++){
                cout << argv[colargindx] << endl;
                // if() //add size checking, then split into 2's, then make 2's into color
            }
        }
        // if(string(argv[i]) == "--setcol"){
        //     int colpos = 0;
        //     if(argc-(i+5) < 0){
        //         cout << "not enough args";
        //         return 0;
        //     }
        //     for(int coi = i+1; coi < 5+i; coi++){
        //         int hpindx = 0;
        //         if(argv[coi][0] == '#'){
        //             cout << "\nhash detected\n";
        //             hpindx=1;
        //         }
        //         char hexpair[2];
        //         int rgbbuffer[3];
        //         for(int rbgi = 0; rbgi<3; rbgi++){
                    
        //         }
        //         //upto extracting pairs of hex and making it RGB's
        //     }
        // }
    }
    
    return 0;

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
    for(int args = 1; args < argc; args++){
        if(argv[args] == (char *)"--setcol"){
            cout << "setcol!!\n";
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