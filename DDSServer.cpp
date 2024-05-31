#include "DDSServer.hpp"

int main(int argc, char const *argv[])
{
  DDSBaseSubscriber mysub;
  if (mysub.init())
  {
    mysub.run();
  } 
  return 0;
}
