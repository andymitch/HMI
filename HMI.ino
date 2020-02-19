#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// 6 LANE CONFIGS
#define NORMAL 0
#define MORNING 1
#define AFTERNOON 2
#define WEEKEND 3
#define CLOSED 4
Adafruit_NeoPixel six0 (9, 11/*PIN NO.*/, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel six1 (9, 12/*PIN NO.*/, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel six2 (9, 3/*PIN NO.*/, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel six3 (9, 4/*PIN NO.*/, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel six4 (9, 5/*PIN NO.*/, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel six5 (9, 6/*PIN NO.*/, NEO_GRB + NEO_KHZ800);

// 4 LANE NOFIGS
#define EVEN 0
#define EAST 1
#define WEST 2
Adafruit_NeoPixel four0 (6, 7/*PIN NO.*/, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel four1 (6, 8/*PIN NO.*/, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel four2 (6, 9/*PIN NO.*/, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel four3 (6, 10/*PIN NO.*/, NEO_GRB + NEO_KHZ800);

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  pinMode(2, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  six0.begin();
  six1.begin();
  six2.begin();
  six3.begin();
  six4.begin();
  six5.begin();
  four0.begin();
  four1.begin();
  four2.begin();
  four3.begin();
}


void clearAll() {
  six0.clear();
  six1.clear();
  six2.clear();
  six3.clear();
  six4.clear();
  six5.clear();
  four0.clear();
  four1.clear();
  four2.clear();
  four3.clear();
}

void setLanes_A(int index, int laneConfig) {
  switch(laneConfig) {
    case NORMAL:
      six0.fill(six0.Color(10,10,10),     index, 4);
      six0.show();
      six1.fill(six1.Color(10,10,10),     index, 4);
      six1.show();
      six2.fill(six2.Color(10,10,10),     index, 4);
      six2.show();
      six3.fill(six3.Color(10,10,10), 8 - index, 4);
      six3.show();
      six4.fill(six4.Color(10,10,10), 8 - index, 4);
      six4.show();
      six5.fill(six5.Color(10,10,10), 8 - index, 4);
      six5.show();
      break;
    case MORNING:
      six0.fill(six0.Color(10,10,10),     index, 4);
      six0.show();
      six1.fill(six1.Color(10,10,10), 8 - index, 4);
      six1.show();
      six2.fill(six2.Color(10,10,10), 8 - index, 4);
      six2.show();
      six3.fill(six3.Color(10,10,10), 8 - index, 4);
      six3.show();
      six4.fill(six4.Color(10,10,10), 8 - index, 4);
      six4.show();
      six5.fill(six5.Color(10,10, 0), 8 - index, 4);
      six5.show();
      break;
    case AFTERNOON:
      six0.fill(six0.Color(10,10, 0),     index, 4);
      six0.show();
      six1.fill(six1.Color(10,10,10),     index, 4);
      six1.show();
      six2.fill(six2.Color(10,10,10),     index, 4);
      six2.show();
      six3.fill(six3.Color(10,10,10),     index, 4);
      six3.show();
      six4.fill(six4.Color(10,10,10),     index, 4);
      six4.show();
      six5.fill(six5.Color(10,10,10), 8 - index, 4);
      six5.show();
      break;
    case WEEKEND:
      six0.fill(six0.Color( 0,10, 0),     index, 4);
      six0.show();
      six1.fill(six1.Color(10,10, 0),     index, 4);
      six1.show();
      six2.fill(six2.Color(10,10,10),     index, 4);
      six2.show();
      six3.fill(six3.Color(10,10,10), 8 - index, 4);
      six3.show();
      six4.fill(six4.Color(10,10, 0), 8 - index, 4);
      six4.show();
      six5.fill(six5.Color( 0,10, 0), 8 - index, 4);
      six5.show();
      break;
    case CLOSED:
      six0.fill(six0.Color( 0, 0,10),     index, 4);
      six0.show();
      six1.fill(six1.Color( 0, 0,10),     index, 4);
      six1.show();
      six2.fill(six2.Color( 0,10, 0),     index, 4);
      six2.show();
      six3.fill(six3.Color( 0,10, 0), 8 - index, 4);
      six3.show();
      six4.fill(six4.Color( 0, 0,10), 8 - index, 4);
      six4.show();
      six5.fill(six5.Color( 0, 0,10), 8 - index, 4);
      six5.show();
      break;
  }
}

void setLanes_B(int index, int laneConfig) {
  switch(laneConfig) {
    case EVEN:
      four0.fill(four0.Color( 0,10, 0), 8 - index, 4);
      four0.show();
      four1.fill(four1.Color(10,10,10), 8 - index, 4);
      four1.show();
      four2.fill(four2.Color(10,10,10),     index, 4);
      four2.show();
      four3.fill(four3.Color( 0,10, 0),     index, 4);
      four3.show();
      break;
    case EAST:
      four0.fill(four0.Color( 0,10, 0), 8 - index, 4);
      four0.show();
      four1.fill(four1.Color(10,10,10), 8 - index, 4);
      four1.show();
      four2.fill(four2.Color(10,10,10), 8 - index, 4);
      four2.show();
      four3.fill(four3.Color(10,10,10),     index, 4);
      four3.show();
      break;
    case WEST:
      four0.fill(four0.Color(10,10,10), 8 - index, 4);
      four0.show();
      four1.fill(four1.Color(10,10,10),     index, 4);
      four1.show();
      four2.fill(four2.Color(10,10,10),     index, 4);
      four2.show();
      four3.fill(four3.Color( 0,10, 0),     index, 4);
      four3.show();
      break;
  }
}


int config6 = NORMAL;
int config4 = EVEN;

void nextConfig(){
  if (config6 == CLOSED) config6 = NORMAL;
  else config6++;
  if (config4 == WEST) config4 = EVEN;
  else config4++;
}


int currState = 0;
int prevState = 0;

void loop() {
  for(int i = 0; i < 9; i ++) {
    currState = digitalRead(2);
    if(currState != prevState) {
      if(currState == HIGH) nextConfig();
      prevState = currState;
    }
    clearAll();
    setLanes_A(i, config6);
    setLanes_B(i, config4);
    delay(250);
  }
}
