#include"directory.hpp"
#include"directory.cpp"

int main(){

Commandterm Name(openFile("DMV_DATABASE.txt"));

return 0;
}

/*CREATE TRIGGER tr_update_car_count
AFTER INSERT ON Vehicle
FOR EACH ROW
BEGIN
  UPDATE Civilian
  SET cars_owned = cars_owned + 1
  WHERE id_number = NEW.id_number;
END;*/