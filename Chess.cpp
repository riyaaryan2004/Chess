#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string.h>
#include <iomanip>
#include <windows.h>
#include <vector>
using namespace std;

class ChessBoard;
class position{
 public:
   int x=-1,y=-1;
   position(){}
   position(int i,int j) {
    x=i;
    y=j;
   }
   void show_data(){
   cout<<"position is"<<x<<","<<y<<endl;
   }
};
class element{
 public:
    position p;
    int data;
    int type;
    int clr;
    void set_pos(int i,int j){
    p.x=i;
    p.y=j;
    }
    void show_data(){
     cout<<"position is"<<p.x<<","<<p.y<<endl;
     cout<<"data is"<<data<<endl;
     cout<<"type is"<<type<<endl;
     if(clr==1){
     cout<<"colour is white"<<endl;
     }else if(clr==2){
     cout<<"colour is black"<<endl;
     }
    }

};
class pawn{
 public:
  position p;
  int type=5;
  int color;  // 1 for white & 2 for black
  pawn(){}
  pawn(int c){
   color=c;
  }
  vector<position> possible_moves(int i,int j,ChessBoard* b);//////////

};
class king{
 public:
  position p;
  int type=0;
  int color; // 1 for white & 2 for black
  king(){}
  king(int c){
   color=c;
  }
  vector<position> possible_moves(int i,int j,ChessBoard*b);


};
class queen{
public:
  position p;
  int type=1;
  int color; // 1 for white & 2 for black
  queen(){}
  queen(int c){
   color=c;
  }
  vector<position> possible_moves(int i,int j,ChessBoard*b);


};
class bishop{
public:
  position p;
  int type=2;
  int color; // 1 for white & 2 for black
  bishop(){}
  bishop(int c){
   color=c;
  }
  vector<position> possible_moves(int i,int j,ChessBoard*b);


};
class knight{
public:
  position p;
  int type=3;
  int color; // 1 for white & 2 for black
  knight(){}
  knight(int c){
   color=c;
  }
  vector<position> possible_moves(int i,int j,ChessBoard*b);


};
class rook{
public:
  position p;
  int type=4;
  int color; // 1 for white & 2 for black
  rook(){}
  rook(int c){
   color=c;
  }
  vector<position> possible_moves(int i,int j,ChessBoard*b);


};

class ChessBoard{
  public:
    element board[8][8];
    ChessBoard(){
    // 0&1 index for white(1) // 6&7 index for black(2)
for(int j = 0; j < 8; j++){
    if(j == 0){
        for(int i = 0; i < 8; i++){
            if(i == 0 || i == 7){
                board[i][j].data = 14;
            } else if(i == 1 || i == 6){
                board[i][j].data = 13;
            } else if(i == 2 || i == 5){
                board[i][j].data = 12;
            } else if(i == 3){
                board[i][j].data = 11;
            } else if(i == 4){
                board[i][j].data = 10;
            }
        }
    } else if(j == 1){
        for(int i = 0; i < 8; i++){
            board[i][j].data = 15;
        }
    } else if(j == 2 || j == 3 || j == 4 || j == 5){
        for(int i = 0; i < 8; i++){
            board[i][j].data = 0;
        }
    } else if(j == 6){
        for(int i = 0; i < 8; i++){
            board[i][j].data = 25;
        }
    } else if(j == 7){
        for(int i = 0; i < 8; i++){
            if(i == 0 || i == 7){
                board[i][j].data = 24;
            } else if(i == 1 || i == 6){
                board[i][j].data = 23;
            } else if(i == 2 || i == 5){
                board[i][j].data = 22;
            } else if(i == 3){
                board[i][j].data = 21;
            } else if(i == 4){
                board[i][j].data = 20;
            }
        }
    }
}
    }
    ~ChessBoard() {
        //cout << "ChessBoard destructor" << endl;
    }

 void print_chessboard(){
    system("color 60"); //yellow(6) background//black(0)text
    cout<<endl<<endl;
    #define BLACK_BOX   "\033[40;33m"   // first digit 4 for background and 3 for text color change
    #define WHITE_BOX   "\033[47;33m"   //
    #define YELLOW_BACKGROUND "\033[43;33m"   //
    #define YELLOW_BLACK "\033[43;30m"

    string  s="   ";
    string  S="            ";
    string  King="    KING    "; //0
    string  Q="   QUEEN    "; //1
    string  B="   BISHOP   ";//2
    string  K="   KNIGHT   ";//3
    string  R="    ROOK    ";//4
    string  P="    PAWN    ";//5

    string  color;
    string  temp;

    for(int j=8;j>0;j--){

      string box1;
      string box2;
      if(j%2==0){
      box1= BLACK_BOX;
      box2= WHITE_BOX;
      }else{
      box1=WHITE_BOX ;
      box2= BLACK_BOX;
      }

      for(int k=1;k<=5;k++){

         for(int i=1;i<=8;i++) {
            int val=board[i-1][j-1].data;
            cout<< YELLOW_BLACK ;
            if(i==1){
              if(k==3){ cout<<' '<<j<<' ';}
              else{cout<<s;}
            }

            if(i%2==0){cout<<box2;}
            else{cout<<box1;}

            if(val/10==1){
            color="   White    ";
            }else if(val/10==2){
            color="   Black    ";
            }else if(val==0){ color="            ";}


            int type=val%10;

            switch (type){
            case 0:
               temp=King;
               break;
            case 1:
               temp=Q ;
               break;
            case 2:
               temp= B;
               break;
            case 3:
               temp= K ;
               break;
            case 4:
               temp= R ;
               break;
            case 5:
               temp= P;
               break;

            }
            if(val==0){
                temp="            ";
            }


            if(k==1||k==3||k==5){
               cout<<S;
            }else if(k==2){
               cout<<temp;
            }else{
               cout<<color;
            }
         }
         cout<<YELLOW_BACKGROUND<<" ."<<endl;
       }
    }
    cout<<YELLOW_BACKGROUND<<endl;
    cout<<YELLOW_BLACK<<"        a           b           c           d           e           f           g           h      "<< endl;




    }


    void print_board_data(){
      for(int j=7;j>=0;j--){
         cout<<j+1<<"  ";
         for(int i=0;i<8;i++){
            cout<<setw(2)<<board[i][j].data<<" ";
         }
         cout<<endl;
      }
      cout<<endl;
      cout<<"   ";
      for(int i=1;i<=8;i++){
            char I=i+97-1;
            cout<<setw(2)<<I<<" ";
      }
      cout<<endl<<endl;
    }
};     //chessboard class end here

vector<position> pawn::possible_moves(int i,int j,ChessBoard* b){
    int val=b->board[i][j].data;
   // cout<<val<<endl; //check
    vector<position> possible_pos;
    int direction;
    int oppostite_color;
    if(val/10==1){
         direction=1;
         oppostite_color=2;
    }
    else if(val/10==2){
         direction=-1;
         oppostite_color=1;
    }
    for(int x=i-1;x<=i+1;x++){
          int y=j+direction;
          if(x>=0&&x<=7&&y>=0&&y<=7){
              int pos_data=b->board[x][y].data;
              if((pos_data==0&&x==i)||pos_data/10==oppostite_color){
                position temp(x,y);
               // cout<<x<<","<<y<<" "; //to check
                possible_pos.push_back(temp);
              }
          }
          y+=direction;
          if((j==1||j==6)&&x>=0&&x<=7&&y>=0&&y<=7){
             int pos_data=b->board[x][y].data;
             if(pos_data==0&&x==i){
                position temp(x,y);
               // cout<<x<<","<<y<<" "; //to check
                possible_pos.push_back(temp);
             }
          }

    }
    return possible_pos;
}

vector<position> king::possible_moves(int i,int j,ChessBoard* b){
    int val=b->board[i][j].data;
    //cout<<val<<endl;
    vector<position> possible_pos;
    int oppostite_color;
    if(val/10==1){
         oppostite_color=2;
    }
    else if(val/10==2){
         oppostite_color=1;
    }
    for(int x=i-1;x<=i+1;x++){
        for(int y=j-1;y<=j+1;y++){
            if(x>=0&&x<=7&&y>=0&&y<=7){
                int pos_data=b->board[x][y].data;
                if((pos_data==0||pos_data/10==oppostite_color)&&(x!=i&&y!=j)){
                position temp(x,y);
                //cout<<x<<","<<y<<" "; //to check
                possible_pos.push_back(temp);
                }
            }

        }
    }
    return possible_pos;
}

vector<position> rook::possible_moves(int i,int j,ChessBoard* b){
   int val=b->board[i][j].data;
   // cout<<val<<endl; //check
    vector<position> possible_pos;
    int oppostite_color;
    if(val/10==1){
         oppostite_color=2;
    }
    else if(val/10==2){
         oppostite_color=1;
    }

    for(int x=i+1;x<8;x++){
        int pos_data=b->board[x][j].data;
          if(pos_data/10==val/10)
            break;
          if(pos_data==0||pos_data/10==oppostite_color){
            position temp(x,j);
                //cout<<x<<","<<j<<" "; //to check
                possible_pos.push_back(temp);
          }
          if(pos_data/10==oppostite_color)
            break;
    }
    for(int x=i-1;x>=0;x++){
        int pos_data=b->board[x][j].data;
          if(pos_data/10==val/10)
          break;
          if(pos_data==0||pos_data/10==oppostite_color){
            position temp(x,j);
                //cout<<x<<","<<j<<" "; //to check
                possible_pos.push_back(temp);
          }
          if(pos_data/10==oppostite_color)
            break;
    }
    for(int y=j+1;y<=7;y++){
        int pos_data=b->board[i][y].data;
          if(pos_data/10==val/10)
          break;
          if(pos_data==0||pos_data/10==oppostite_color){
            position temp(i,y);
                //cout<<i<<","<<y<<" "; //to check
                possible_pos.push_back(temp);
          }
          if(pos_data/10==oppostite_color)
            break;
    }
    for(int y=j-1;y>=0;y--){
          int pos_data=b->board[i][y].data;
          if(pos_data/10==val/10)
          break;
          if(pos_data==0||pos_data/10==oppostite_color){
            position temp(i,y);
                //cout<<i<<","<<y<<" "; //to check
                possible_pos.push_back(temp);
          }
          if(pos_data/10==oppostite_color)
            break;
    }
    return possible_pos;

}

vector<position> knight::possible_moves(int i,int j,ChessBoard* b){
    int val=b->board[i][j].data;
    //cout<<val<<endl; //check
    vector<position> possible_pos;
    int oppostite_color;
    if(val/10==1){
         oppostite_color=2;
    }
    else if(val/10==2){
         oppostite_color=1;
    }
    for(int x=i-2;x<=i+2;x++){
        if((x==i-2||x==i+2)&&(x>=0&&x<=7)){
           int y=j-1;
           if(y>=0){
             int pos_data=b->board[x][y].data;
             if(pos_data==0||pos_data/10==oppostite_color){
                 position temp(x,y);
                 //cout<<x<<","<<y<<" "; //to check
                 possible_pos.push_back(temp);
             }
           }
           y=j+1;
           if(y<=7){
             int pos_data=b->board[x][y].data;
             if(pos_data==0||pos_data/10==oppostite_color){
                 position temp(x,y);
                // cout<<x<<","<<y<<" "; //to check
                 possible_pos.push_back(temp);
             }
           }
        }
        if((x==i-1||x==i+1)&&(x>=0&&x<=7)){
           int y=j-2;
           if(y>=0){
             int pos_data=b->board[x][y].data;
             if(pos_data==0||pos_data/10==oppostite_color){
                 position temp(x,y);
                 //cout<<x<<","<<y<<" "; //to check
                 possible_pos.push_back(temp);
             }
           }
           y=j+2;
           if(y<=7){
             int pos_data=b->board[x][y].data;
             if(pos_data==0||pos_data/10==oppostite_color){
                 position temp(x,y);
                 //cout<<x<<","<<y<<" "; //to check
                 possible_pos.push_back(temp);
             }
           }
        }
    }
    return possible_pos;

}

vector<position> bishop::possible_moves(int i,int j,ChessBoard* b){
    int val=b->board[i][j].data;
    //cout<<val<<endl; //check
    vector<position> possible_pos;
    int oppostite_color;
    if(val/10==1){
         oppostite_color=2;
    }
    else if(val/10==2){
         oppostite_color=1;
    }
    for(int x=i+1,y=j+1;max(x,y)<=7;x++,y++){
          int pos_data=b->board[x][y].data;
          if(pos_data/10==val/10)
          break;
          if(pos_data==0||pos_data/10==oppostite_color){
            position temp(x,y);
                //cout<<x<<","<<y<<" "; //to check
                possible_pos.push_back(temp);
          }
          if(pos_data/10==oppostite_color)
            break;
    }
    for(int x=i-1,y=j-1;min(x,y)>=0;x--,y--){
          int pos_data=b->board[x][y].data;
          if(pos_data/10==val/10)
          break;
          if(pos_data==0||pos_data/10==oppostite_color){
            position temp(x,y);
                //cout<<x<<","<<y<<" "; //to check
                possible_pos.push_back(temp);
          }
          if(pos_data/10==oppostite_color)
            break;

    }
    for(int x=i+1,y=j-1;(max(x,y)<=7)&&(min(x,y)>=0);x++,y--){
          int pos_data=b->board[x][y].data;
          if(pos_data/10==val/10)
          break;
          if(pos_data==0||pos_data/10==oppostite_color){
            position temp(x,y);
                //cout<<x<<","<<y<<" "; //to check
                possible_pos.push_back(temp);
          }
          if(pos_data/10==oppostite_color)
            break;
    }
    for(int x=i-1,y=j+1;(max(x,y)<=7)&&(min(x,y)>=0);x--,y++){
          int pos_data=b->board[x][y].data;
          if(pos_data/10==val/10)
          break;
          if(pos_data==0||pos_data/10==oppostite_color){
            position temp(x,y);
                //cout<<x<<","<<y<<" "; //to check
                possible_pos.push_back(temp);
          }
          if(pos_data/10==oppostite_color)
            break;
    }
     return possible_pos;
}

vector<position> queen::possible_moves(int i,int j,ChessBoard* b){
    int val=b->board[i][j].data;
    //cout<<val<<endl; //check
    vector<position> possible_pos;
    bishop B; rook R;
    vector<position> bishop_pos=B.possible_moves(i,j,b);
    vector<position> rook_pos=R.possible_moves(i,j,b);
    int size_B=bishop_pos.size();
    int size_R=rook_pos.size();

    for(int i=0;i<size_B;i++){
        possible_pos.push_back(bishop_pos[i]);
    }
    for(int i=0;i<size_R;i++){
        possible_pos.push_back(rook_pos[i]);
    }
    int size=possible_pos.size();

    return possible_pos;
}

element* chesspiece_data(int i,int j,ChessBoard*b){
    element* e=new element;
    e->data=b->board[i][j].data;
    cout<<e->data<<endl;
    if(e->data==0){
        cout<<"no chesspiece at this pos"<<endl;
        delete e; // Free memory allocated for element
        return nullptr;
    }
    e->clr=e->data/10;
    e->type=e->data%10;
    e->set_pos(i,j);
    //e->show_data();
    return e;
}
int if_king_check(int i,int j,ChessBoard*b){
    element* KING=nullptr;
    KING=chesspiece_data(i,j,b);
    if (KING == nullptr) {
        cout << "Invalid position" << endl;
        return -1; // Error code to indicate invalid position
    }
    king kng;
    pawn p;
    queen q;
    knight k;
    bishop bis;
    rook r;
    element*temp=nullptr;
    vector <position> possible_moves_ForCheck;
    int check=0;
    int Size=0;

            for (int piece = 0; piece <= 5; piece++) {
            switch (piece) {
                case 0:
                    possible_moves_ForCheck = kng.possible_moves(i, j, b);
                    Size=possible_moves_ForCheck.size();
                    break;

                case 1:
                    possible_moves_ForCheck = q.possible_moves(i, j, b);
                    Size=possible_moves_ForCheck.size();
                    break;
                case 2:
                    possible_moves_ForCheck = bis.possible_moves(i, j, b);
                    Size=possible_moves_ForCheck.size();
                    break;
                case 3:
                    possible_moves_ForCheck = k.possible_moves(i, j, b);
                    Size=possible_moves_ForCheck.size();
                    break;

                case 4:
                    possible_moves_ForCheck = r.possible_moves(i, j, b);
                    Size=possible_moves_ForCheck.size();
                    break;

                case 5:
                    possible_moves_ForCheck = p.possible_moves(i, j, b);
                    Size=possible_moves_ForCheck.size();
                    break;

                default:
                    break;
            }

         for(int i=Size-1;i>=0;i--){
              int x=possible_moves_ForCheck[i].x;   int y=possible_moves_ForCheck[j].y;
              temp=chesspiece_data(x,y,b);
              if(temp==nullptr){                 //temp null when data at (x,y)is 0 i.e; no chesspiece at that position
              continue;
              }
              else if(temp->type==KING->type){
                cout<<"checkmate for color "<<KING->clr<<endl;
                check=1;
                delete KING; // Free memory allocated for KING
                delete temp; // Free memory allocated for temp
                cout<<"KING is checked by type"<<temp->type<<endl;
                return check;
              }
               else if(temp->clr==KING->clr){
                continue;
              }
         }

        }
    //}
    //cout<<"not checked"<<endl;
    delete KING; // Free memory allocated for king
    return check;
}
class player {
private:
    std::string name;  // Use std::string to manage the name
    int score = 0;
    bool isWinner=0;
public:
    int color = 0;
    // Constructor to initialize color and potentially name
    explicit player(int c, const std::string& playerName = "") : color(c), name(playerName) {}
    // No need for a custom destructor since std::string manages its memory
    ~player() = default;
    void set_data() {
        std::getline(std::cin, name);  // Read full line to allow names with spaces
    }
    void set_winner(){
        isWinner=1;
    }

    // Function to get the player's name
    void get_name() const {
        if (!name.empty())
            std::cout << name;
        else
            std::cout << "Name not set." << std::endl;
    }

    void add_score(int points) {
        score += points;
    }

    int get_score() const {
        return score;
    }
};
int getPoints(int type){
 if(type==-1) return 0;
 if(type==1) return 9;
 if(type==2||type==3) return 3;
 if(type==4) return 5;
 if(type==5) return 1;

}

void move(int p,int q,int r,int s,ChessBoard*b){
 b->board[r][s].data=b->board[p][q].data;
 b->board[p][q].data=0;
}
int play(player & PLAYER,ChessBoard *b){                 //return 0 if player moves//return 1 if player enters invalid position
   int p,q,r,s;
   //int
   char charP,charQ,charR,charS;
   cout<<"Now it's your turn ";PLAYER.get_name();cout<<endl;
   cout<<"Enter the position of chesspiece to be moved :";
   cout<<endl<<endl<<endl;
   cout<<"PRESS QT to Quit the game"<<endl;
   std::cout << "\033[46;47H";
   cin>>charP>>charQ;

   if(charP=='a'||charP=='A'){
    p=1;
   }else if(charP=='b'||charP=='B'){
    p=2;
   }else if(charP=='c'||charP=='C'){
    p=3;
   }else if(charP=='d'||charP=='D'){
    p=4;
   }else if(charP=='e'||charP=='E'){
    p=5;
   }else if(charP=='f'||charP=='F'){
    p=6;
   }else if(charP=='g'||charP=='G'){
    p=7;
   }else if(charP=='h'||charP=='H'){
    p=8;
   }else if((charP=='q'||charP=='Q')&&(charQ=='t'||charQ=='T')){
      return 4;
   }else{
    p=9;
   }
   //p = charP - '0';
   q = charQ - '0';

   if(p<1||q<1||p>8||q>8){
    cout<<"enter each coordinates between 1-8 and a-h"<<endl;
    return -1;
   }
   if(b->board[p-1][q-1].data/10!=PLAYER.color){
      if(b->board[p-1][q-1].data==0){
        cout<<"There is no Chesspiece at this position "<<endl;
        return -1;
      }
    cout<<"This is not your chesspiece ";PLAYER.get_name();cout<<endl;
    return -1;
   }
   std::cout << "\033[47;0H";
   cout<<"enter the position of chesspiece to be placed :";
   cin>>charR>>charS;

   if(charR=='a'||charR=='A'){
    r=1;
   }else if(charR=='b'||charR=='B'){
    r=2;
   }else if(charR=='c'||charR=='C'){
    r=3;
   }else if(charR=='d'||charR=='D'){
    r=4;
   }else if(charR=='e'||charR=='E'){
    r=5;
   }else if(charR=='f'||charR=='F'){
    r=6;
   }else if(charR=='g'||charR=='G'){
    r=7;
   }else if(charR=='h'||charR=='H'){
    r=8;
   }else if((charR=='q'||charR=='Q')&&(charR=='t'||charR=='T')){
    return 4;
   }else{
    r=9;
   }
   //r = charR - '0';
   s = charS - '0';

   if(r<1||s<1||r>8||s>8){
    cout<<"enter each coordinates between 1-8 and a-h"<<endl;
    return -1;
   }
   int type= (b->board[p-1][q-1].data)%10;
   vector<position> v;
   int Size=0;
   int typeOfPieceAtDestination;
   if(b->board[r-1][s-1].data==0){
    typeOfPieceAtDestination=-1;
   }else{
    typeOfPieceAtDestination=(b->board[r-1][s-1].data)%10;

   }
  // int colorOfKingAttacked=0;
    king KING;
    queen QUEEN;
    bishop BISHOP;
    knight KNIGHT;
    rook ROOK;
    pawn PAWN;

   switch(type){
                case 0:
                    v = KING.possible_moves(p-1,q-1, b);
                    Size=v.size();
                    break;

                case 1:
                    v = QUEEN.possible_moves(p-1,q-1, b);
                    Size=v.size();
                    break;

                case 2:
                    v = BISHOP.possible_moves(p-1,q-1, b);
                    Size=v.size();
                    break;

                case 3:
                    v = KNIGHT.possible_moves(p-1,q-1, b);
                    Size=v.size();
                    break;

                case 4:
                    v = ROOK.possible_moves(p-1,q-1, b);
                    Size=v.size();
                    break;

                case 5:
                    v = PAWN.possible_moves(p-1,q-1, b);
                    Size=v.size();
                    break;

                default:
                    break;
   }
   for(int i=0;i<Size;i++){
    if(v[i].x==r-1 &&v[i].y==s-1){
        PLAYER.add_score(getPoints(typeOfPieceAtDestination));
        move(p-1,q-1,r-1,s-1,b);
        if(typeOfPieceAtDestination==0){
            return PLAYER.color;
        }
        return 0;
    }
   }
   cout<<"This is not valid destination for chesspiece at position :"<<p<<","<<q<<endl;
   return -1;
}
void welcome()
{
    system("color 0E");
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t  _____            ____              _____  " << endl;
    cout << "\t\t\t\t\t\t\t /____/|          /___/|            /____/| " << endl;
    cout << "\t\t\t\t\t\t\t $$$$/ |          $$$| |  ________  $$$$| |  __________   _________   ______   _________   ________ " << endl;
    cout << "\t\t\t\t\t\t\t $$$$  |          $$$| | /       /| $$$$| | /         /| /        /| /      \\_/         | /       /|" << endl;
    cout << "\t\t\t\t\t\t\t $$$$  |   ____   $$$| | $$$$$$$$ | $$$$| | $$$$$$$$$  | $$$$$$$$$ | $$$$$$$$ $$$$$$$$$ | $$$$$$$$ | " << endl;
    cout << "\t\t\t\t\t\t\t $$$$  |  $$$$ \\  $$$| | $      $ | $$$$| | $$$$$$$$$_/  $$$$$$$$$ | $$$$$$$$$$$$$$$$$$ | $      $ |" << endl;
    cout << "\t\t\t\t\t\t\t $$$$  | $$$ $$ \\ $$$| | $$$$$$$$/  $$$$| | $$  |        $$     $$ | $$$ |  $$$ |   $$$ | $$$$$$$$/ " << endl;
    cout << "\t\t\t\t\t\t\t $$$$  |$$$   $$ \\$$$| | $$     __  $$$$| | $$  |______  $$     $$ | $$$ |  $$$ |   $$$ | $$     __ " << endl;
    cout << "\t\t\t\t\t\t\t $$$$ /$$$     $$ $$$| | $$    / /| $$$$| | $$  /_____/| $$     $$ | $$$ |  $$$ |   $$$ | $$    / /| " << endl;
    cout << "\t\t\t\t\t\t\t $$$$/$$$       $$$$$| / $$    $$ | $$$$| | $$$$$$$$$ || $$$$$$$$$ | $$$ |  $$$ |   $$$ | $$    $$ | " << endl;
    cout << "\t\t\t\t\t\t\t $$$$$$$         $$$$|/  $$$$$$$$/  $$$$|/  $$$$$$$$$_/  $$$$$$$$$/  $$$/   $$$/    $$$/  $$$$$$$$/  " << endl;
    cout <<  "\n\n\n\n\n";
    cout << endl;
   // std::cout << "\033[1;46;32m Press ENTER to start the game."<<"\033[42;32m  .  " <<"\033[1;46;36m  .  "<< std::endl;
    //std::cout << "\033[1;46;32m Press ENTER to start the game."<<"\033[0m  hi " << std::endl;

    cout << "     Press ENTER to start the game. "  << endl;
    std::cin.get();
    system("cls");
}
class game{
 public:
 ChessBoard *board;
 pawn p;
 king kng;
 queen q;
 knight k;
 bishop b;
 rook r;


 game(){
  board = new ChessBoard();
  welcome();
  system("color 0A");
  //cout<<"WELCOME TO THE CHESS WORLD"<<endl;
  player p1(1),p2(2);

  cout<<endl<<endl<<endl;
  cout<<"        Enter the Name of player 1 : ";
  p1.set_data();
  cout<<"        Enter the Name of player 2 : ";
  p2.set_data();
  system("cls");
  cout<<endl<<endl<<endl;
  cout<<"    \033[40;32m    WELCOME ";p1.get_name();cout<<" and ";p2.get_name();cout<<" \033[40;37m"<<endl<<endl<<endl;

  cout<<"      "<<"\033[46;37m";p1.get_name();cout<<" your colour is WHITE "<<"\033[40;37m"<<endl<<endl;
  cout<<"      "<<"\033[46;30m";p2.get_name();cout<<" your colour is BLACK "<<"\033[40;37m"<<endl<<endl;
  cout<<endl<<"  Press ENTER to start the game. "<<endl;
  std::cin.get();
  system("cls");

  int a, b;
  while(1){
    do {
        board->print_chessboard();
        a = play(p1, board);
        if(a==-1){
            cout<<"Press ENTER to input Data again "<<endl;
            std::cin.get();std::cin.get();  // Wait for Enter key press
        }
        system("cls");
    } while (a == -1);  // Repeat player 1's turn if the turn was not successful
    if(a==1){
        p1.set_winner();
        cout<<"CONGRATULATIONS ";p1.get_name();cout<<" you are the winner"<<endl;
        break;
    }else if(a==4){
        cout<<endl<<endl<<endl<<endl;
        cout<<"                   GAME OVER "<<endl<<endl<<endl<<endl;
        cout<<"    ";p1.get_name();cout<<" : Score = "<<p1.get_score()<<endl<<endl;
        cout<<"    ";p2.get_name();cout<<" : Score = "<<p2.get_score()<<endl<<endl<<endl;

        cout<<"         THANK YOU for playing the game   "<<endl<<endl<<endl<<endl;
        break;
    }
    do {
        board->print_chessboard();
        b = play(p2, board);
        if(b==-1){cout<<"Press ENTER to input Data again "<<endl;
            std::cin.get();std::cin.get();  // Wait for Enter key press
        }
        system("cls");

    } while (b == -1);  // Repeat player 2's turn if the turn was not successful
    if(b==2){
        p2.set_winner();
        cout<<"CONGRATULATIONS ";p2.get_name();cout<<" you are the winner"<<endl;
        break;
    }else if(b==4){
        cout<<endl<<endl<<endl<<endl;
        cout<<"                   GAME OVER "<<endl<<endl<<endl<<endl;
        cout<<"    ";p1.get_name();cout<<" : Score = "<<p1.get_score()<<endl<<endl;
        cout<<"    ";p2.get_name();cout<<" : Score = "<<p2.get_score()<<endl<<endl<<endl;

        cout<<"         THANK YOU for playing the game   "<<endl<<endl<<endl<<endl;
        break;
    }
  }


 }
 ~game() {
        delete board;
 }

};


int main(){
  game g;

  return 0;
}








