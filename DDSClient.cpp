#include "DDSClient.hpp"

int main(int argc, char const *argv[])
{
  DDSBasePublisher mypub;
  if (mypub.init())
  {
    mypub.run();
  }
  return 0;
}
