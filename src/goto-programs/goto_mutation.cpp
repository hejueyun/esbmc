#include <goto-programs/goto_mutation.h>
#include <random>

using u32 = uint_least32_t;
using engine = std::mt19937;

void mutateOrder(
  goto_functionst &func,
  messaget &msg)
{
  char data[100];

  int cnt = 0;
  // get "main"
  goto_functionst::function_mapt::iterator m_it =
    func.function_map.find("c:@F@main");
  std::ostringstream os;
  if(m_it != func.function_map.end())
  {
    goto_programt &mmain = m_it->second.body;
    int program_len = mmain.instructions.size();

    char data[program_len];
    std::random_device os_seed;
    const u32 seed = os_seed();

    engine generator(seed);
    std::uniform_int_distribution<u32> distribute(1, 100);
    for(auto d : data)
    {
      d = char(distribute(generator));
    }

    while(cnt <= 21 && cnt < sizeof(data) / sizeof(data[0]))
    {
      int ran1 = ((int)data[cnt]) % program_len; // convert to integer
      cnt++;
      if(cnt > 11)
        break;
      int ran2 = ((int)data[cnt]) % program_len;
      cnt++;
      int cnt_loop = 0;
      if(ran1 == ran2)
      {
        ran2 += 1;
      }
      if(ran1 > ran2)
      {
        int tmp = ran1;
        ran1 = ran2;
        ran2 = tmp;
      }
      goto_programt::instructionst::iterator tmp2 =
        (mmain).instructions.begin();
      goto_programt::instructiont &instruction = *tmp2;

      Forall_goto_program_instructions(it, mmain)
      {
        if(cnt_loop == ran1)
        {
          instruction = *it;
        }
        if(cnt_loop == ran2)
        {
          instruction.output_instruction(
            *migrate_namespace_lookup, "c:@F@main", os, msg, false);
          os << "swap to \n";
          instruction.swap(*it);
          instruction.output_instruction(
            *migrate_namespace_lookup, "c:@F@main", os, msg, false);
          os << "\n";
          os.clear();
          break;
        }
        cnt_loop++;
      }
    }
    os << "Fuzz End\n";

    os << "Show modified\n";
    os.clear();
    Forall_goto_program_instructions(it, mmain)
    {
      (*it).output_instruction(
        *migrate_namespace_lookup, "c:@F@main", os, msg, false);
    }
  }

  // std::ostringstream oss;
  // func.output(ns, os);
  msg.status(os.str());
}