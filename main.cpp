#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

//#aa84bf #84bf88 #735648 #734857 #ad667f
//(170, 132, 191) (132, 191, 136) (115, 86, 72) (115, 72, 87) 


int getnumber(const char *askfor);

const int defaultpxmax = 7;

int main(int argc, char *argv[]){
    sf::Image imgtex;
    int width, height, pxmax = defaultpxmax, pixelcount = 0;
    sf::Color cols[4] = {sf::Color(170, 132, 191), sf::Color(132, 191, 136), sf::Color(115, 86, 72), sf::Color(115, 72, 87)};
    string imgToOpen = "ref.png";

    //loops through all args
    for(int curarg = 1; curarg < argc; curarg++){
        if(string(argv[curarg]) == "--setcol"){
            curarg++;
            if(argc-(curarg+4) < 0){
                cout << "not enough args\n";
                return 0;
            }
            //loops though specifically the colour args
            for(int colargindx = curarg; colargindx < curarg+4; colargindx++){
                cout << argv[colargindx] << endl;
                if(string(argv[colargindx]).size() < 6){
                    cout << "hex value not long enough\n";
                    return -1;
                }
                int rgb[3];
                for(int rgbindx = 0; rgbindx < 6; rgbindx+=2){
                    // cout << "letters in colour arg: " << string(argv[colargindx]).substr(rgbindx, 2)<< endl;
                    try{
                        rgb[rgbindx/2] = stoi(string(argv[colargindx]).substr(rgbindx, 2), 0, 16);
                        cout << "rgb val: " << rgb[rgbindx/2] << endl;
                    }
                    catch (invalid_argument){
                        cout << "error in hex formatting. make sure there is no #\'s\n";
                        return 0;
                    }
                }
                cout << "adding to cols [" << colargindx-curarg << "]\n";
                cols[colargindx-curarg] = sf::Color(rgb[0], rgb[1], rgb[2]);
            }
            curarg+=3;
        }
        else{
            try{
                cout << "stoi arg: " << argv[curarg] << endl;
                pxmax = stoi(argv[curarg]);
            }
            catch(invalid_argument){
                cout << "error, invalid argument\n";
            }
        }
    }
    
    if(!imgtex.loadFromFile(imgToOpen))
        return -1;
    width = imgtex.getSize().x;
    height = imgtex.getSize().y;
    pxmax = (width*height) * (float)pxmax/100;
    srand(clock());
    sf::Color pxcolor;
    sf::Vector2 pxpos(0, 0);
    
    while (pixelcount < pxmax){
        if(pixelcount < pxmax/4){
            pxcolor = cols[0];
        }
        else if(pixelcount < pxmax/2){
            pxcolor = cols[1];
        }
        else if(pixelcount < (pxmax/4)*3){
            pxcolor = cols[2];
        }
        else{
            pxcolor = cols[3];
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