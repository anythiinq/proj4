#include "agent.h"
#include "provided.h"
#include <string>

Agent::Agent(const IndexBase& index)
 : m_index(index)
{
    // TODO: implement
}

Agent::~Agent()
{
    // TODO: implement
}

bool Agent::load_prompts(const std::string& terms_file, const std::string& summarize_file)
{
	return false; // TODO: replace this line with your implementation
}

bool Agent::query(const std::string& question, std::string& answer)
{
	return false; // TODO: replace this line with your implementation
}
