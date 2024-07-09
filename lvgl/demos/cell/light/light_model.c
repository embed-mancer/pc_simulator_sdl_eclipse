#include "light_model.h"

static int abs_ = 0;                         // ABS报警灯状态 0:关闭  1：打开
static int obd_ = 0;                         // OBD报警灯 0x00:灭 0x01:亮
static int high_beam_ = 0;                   // 远光灯   0x00:关闭   0x01:打开
static int low_beam_ = 0;                    // 近光灯   0x00:关闭   0x01:打开
static int clearance_ = 0;                   // 示廓灯   0x00:关闭   0x01:打开
static int turn_left_ = 0;                   // 左转向   0x00:关闭   0x01:打开 
static int turn_right_ = 0;                  // 右转向   0x00:关闭   0x01:打开
static int location_ = 0;                    // 位置灯状态 0x00 = disable（灭），0x01 = enable(亮)        
static int oil_pressure_ = 0;                // 机油压力灯 0x00 = disable（灭），0x01 = enable(亮)
static int engine_fault_ = 0;                // 发送机故障灯 0x00 = disable（灭），0x01 = enable（亮）
static int brake_ = 0;                       // 刹车制动灯
static int gps_ = 0;                         // GPS
static int key_ = 0;                         // 钥匙
static int wifi_ = 0;                        // WIFI
static int bt_ = 0;                          // 蓝牙
static int maintain_ = 0;                    // 保养
static int cruise_ = 0;                      // 续航灯  00不显示
static int signal_strength_ = 0;             // 基站信号强度
static int mode_ = 0;                        // 驾驶模式
static int tpms_ = 0;                        // 胎压图标
static int drive_assist_ = 0;                // 驾驶辅助
static int mirror_ = 0;                      // 镜像投屏
static int park_ = 0;                        // 驻车
static int auto_hold_ = 0;                   // 启停灯 0：灭  1:亮
static int water_ = 0;                       // 水温
static int tcs_ = 0;                         // 驾驶辅助
static double voltage_ = 0;                  // 电压

int light_model_get_abs() {
  return abs_;
}

int light_model_get_obd() {
  return obd_;
}

int light_model_get_high_beam()  {
  return high_beam_;
}

int light_model_get_low_beam()  {
  return low_beam_;
}

int light_model_get_clearance() {
  return clearance_;
}

int light_model_get_turn_left()  {
  return turn_left_;
}

int light_model_get_turn_right()  {
  return turn_right_;
}

int light_model_get_location()  {
  return location_;
}

int light_model_get_oil_pressure()  {
  return oil_pressure_;
}

int light_model_get_engine_fault()  {
  return engine_fault_;
}

int light_model_get_brake() {
  return brake_;
}

int light_model_get_gps()  {
  return gps_;
}

int light_model_get_key()  {
  return key_;
}

double light_model_get_voltage()  {
  return voltage_;
}

int light_model_get_wifi()  {
  return wifi_;
}

int light_model_get_bt()  {
  return bt_;
}

int light_model_get_maintain() {
  return maintain_;
}

int light_model_get_cruise() {
  return cruise_;
}

int light_model_get_signal_strength() {
  return signal_strength_;
}

int light_model_get_mode() {
  return mode_;
}

int light_model_get_tpms() {
  return tpms_;
}

int light_model_get_tcs() {
  return tcs_;
}

int light_model_get_mirror() {
  return mirror_;
}

int light_model_get_park() {
  return park_;
}

int light_model_get_auto_hold() {
  return auto_hold_;
}

int light_model_get_water() {
  return water_;
}

void light_model_set_abs(int abs) {
  abs_ = abs;
}

void light_model_set_obd(int obd) {
  obd_ = obd;
}

void light_model_set_high_beam(int high_beam) {
  high_beam_ = high_beam;
}

void light_model_set_low_beam(int low_beam) {
  low_beam_ = low_beam;
}

void light_model_set_clearance(int clearance) {
  clearance_ = clearance;
}

void light_model_set_turn_left(int turn_left) {
  turn_left_ = turn_left;
}

void light_model_set_turn_right(int turn_right) {
  turn_right_ = turn_right;
}

void light_model_set_location(int location) {
  location_ = location;
}

void light_model_set_oil_pressure(int oil_pressure) {
  oil_pressure_ = oil_pressure;
}

void light_model_set_engine_fault(int engine_fault) {
  engine_fault_ = engine_fault;
}

void light_model_set_brake(int brake) {
  brake_ = brake;
}

void light_model_set_gps(int gps) {
  gps_ = gps;
}

void light_model_set_key(int key) {
  key_ = key;
}

void light_model_set_voltage(double voltage) {
  voltage_ = voltage;
}

void light_model_set_wifi(int wifi) {
  wifi_ = wifi;
}

void light_model_set_bt(int bt) {
  bt_ = bt;
}

void light_model_set_maintain(int maintain) {
  maintain_ = maintain;
}

void light_model_set_cruise(int cruise) {
  cruise_ = cruise;
}

void light_model_set_signal_strength(int signal_strength) {
  signal_strength_ = signal_strength;
}

void light_model_set_mode(int mode) {
  mode_ = mode;
}

void light_model_set_tpms(int tpms) {
  tpms_ = tpms;
}

void light_model_set_tcs(int tcs) {
  tcs_ = tcs;
}

void light_model_set_park(int park) {
  park_ = park;
}

void light_model_set_auto_hold(int start_stop_light) {
  auto_hold_ = start_stop_light;
}

void light_model_set_water(int value) {
  water_ = value;
}
