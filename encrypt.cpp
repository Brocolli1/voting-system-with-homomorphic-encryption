/* 
 * This program is Licensed under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *   http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. See accompanying LICENSE file.
 */
#include <fstream>

#include <helib/helib.h>

using namespace helib;
using namespace std;


int main(int argc, char* argv[])
{

  std::ifstream inContextFile;
  inContextFile.open("context.json");
  if (inContextFile.is_open()) {
    // Read in the context from the file
    helib::Context context =
        helib::Context::readFromJSON(inContextFile);


      ifstream inPublicKeyFile;
  inPublicKeyFile.open("pk.json");
  if (inPublicKeyFile.is_open()) {
    // Read in the public key from the file
    helib::PubKey publicKey =
        helib::PubKey::readFromJSON(inPublicKeyFile, context);
    
      PtxtArray p2(context);
      if(argc > 1)
        p2 = atoi(argv[1]);
      else 
        p2 = 7;
      Ctxt c2(publicKey);
      p2.encrypt(c2);


        ofstream outCtxtFile;
      outCtxtFile.open("newVote.json", std::ios::out);
      if (outCtxtFile.is_open()) {
        // Write the ctxt to a file
        c2.writeToJSON(outCtxtFile);
        // Close the ofstream
        outCtxtFile.close();
      } 
      else {
        throw std::runtime_error("Could not open file 'ctxt.json'.");
      }


    inPublicKeyFile.close();
  } else {
    throw std::runtime_error("Could not open file 'pk.json'.");
  }

    // Close the ifstream
    inContextFile.close();
  } else {
    throw std::runtime_error("Could not open file 'context.json'.");
  }

  

  return 0;
}
