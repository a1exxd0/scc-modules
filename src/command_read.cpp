#include "command_read.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include <sstream>
#include <cstring>

/**
 * TODO:
 * 
 * Add in module-whatis stuff?
 * test modulefile?
 * initadd?
 */

namespace smod {

// ---------- INPUT ARGUMENT STRUCT ---------- //

bool operator==(const input_arguments &arg1, const input_arguments &arg2) 
{
    return 
        arg1.avail == arg2.avail &&
        arg1.load == arg2.load &&
        arg1.unload == arg2.unload &&
        arg1.spider == arg2.spider &&
        arg1.swap == arg2.swap &&
        arg1.save == arg2.save &&
        arg1.saverm == arg2.saverm &&
        arg1.saveshow == arg2.saveshow &&
        arg1.savelist == arg2.savelist &&
        arg1.restore == arg2.restore &&
        arg1.help == arg2.help &&
        arg1.display == arg2.display &&
        arg1.use == arg2.use &&
        arg1.unuse == arg2.unuse &&
        arg1.reload == arg2.reload &&
        arg1.purge == arg2.purge &&
        arg1.source == arg2.source &&
        arg1.path == arg2.path;
}

// ---------- TEST HELPER ---------- //

char** format_args(std::vector<std::string> &&cmds) 
{
    char** args = new char*[cmds.size() + 1]; // Allocate array of char* pointers

    for (std::size_t i = 0; i < cmds.size(); i++) {
        args[i] = new char[cmds[i].size() + 1]; // Allocate memory for each string (+1 for null terminator)
        std::strcpy(args[i], cmds[i].c_str()); // Copy string into newly allocated memory
    }

    args[cmds.size()] = nullptr; // Null-terminate the array
    return args;
}

char** format_args(std::vector<std::string> &cmds) 
{
    char** args = new char*[cmds.size() + 1]; // Allocate array of char* pointers

    for (std::size_t i = 0; i < cmds.size(); i++) {
        args[i] = new char[cmds[i].size() + 1]; // Allocate memory for each string (+1 for null terminator)
        std::strcpy(args[i], cmds[i].c_str()); // Copy string into newly allocated memory
    }

    args[cmds.size()] = nullptr; // Null-terminate the array
    return args;
}

// ---------- PRIVATE METHODS ---------- //

/**
 * List of possible commands from modulecmd:
 * "avail" -> check what modules are available
 * "load" -> load a module and its dependencies (warning)
 * "unload" -> unload a module and whatever depends on it (warning)
 * "rm" -> alias for unload
 * "spider" -> check dependencies
 * "swap" -> alias for switch
 * "switch" -> Switch loaded modulefile1 with modulefile2. 
 *             If modulefile1 is not specified, then it is assumed to be the
 *             currently loaded module with the same root name as modulefile2.
 * "save" -> save a set of loaded modules
 * "saverm" -> remove that set of modules
 * "saveshow" -> show the modules that a save uses
 * "savelist" -> list available saves
 * "restore" -> restore the set of loaded modules of <name>
 * "help" -> help command
 * "display" -> Display information about one modulefile. The display
 *              sub-command will list the full path of the modulefile and the
 *              environment changes the modulefile will make if loaded. (Note: 
 *              It will not display any environment changes found within conditional 
 *              statements.)
 * "show" -> alias for display
 * "use" -> add a directory to modulepath
 * "unuse" -> remove a directory from modulepath
 * "reload" -> unload and reload all modulefiles
 * "refresh" -> alias for reload
 * "purge" -> unload all modulefiles
 * "source" -> load the modulefile without marking it as loaded
 * "path" -> print path to modulefile
 */

/**
 * @brief Template for interpreting a zero parameter subcommand
 */
template<typename Func>
auto create_func_zero(Func func, const std::string func_name)
{
    return [func, func_name] [[nodiscard]] (std::vector<std::string> params) noexcept(false) {
        if (params.size() != 0) {
            std::ostringstream stream;
            stream << "Expected 0 arguments for `" << func_name << "`, ";
            stream << "received " << params.size() << ". ";
            stream << "Try `smodule help` for help.";
            throw std::invalid_argument(stream.str());
        }
        input_arguments res;
        func(res);
        return res;
    };
}

/**
 * @brief Template for interpreting a single parameter subcommand
 */
template<typename Func>
auto create_func_one(Func func, const std::string func_name)
{
    return [func, func_name] [[nodiscard]] (std::vector<std::string> params) noexcept(false) {
        if (params.size() != 1) {
            std::ostringstream stream;
            stream << "Expected 1 argument for `" << func_name << "`, ";
            stream << "received " << params.size() << ". ";
            stream << "Try `smodule help` for help.";
            throw std::invalid_argument(stream.str());
        }
        input_arguments res;
        func(res, params[0]);
        return res;
    };
}

/**
 * @brief Template for interpreting a multiple parameter subcommand
 */
template<typename Func>
auto create_func_multiple(Func func, const std::string func_name, size_t arg_count)
{
    return [func, func_name, arg_count] [[nodiscard]] (std::vector<std::string> params) noexcept(false) {
        if (params.size() != arg_count) {
            std::ostringstream stream;
            stream << "Expected " << arg_count << " arguments for `";
            stream << func_name << "`, " << "received " << params.size() << ". ";
            stream << "Try `smodule help` for help>>.";
            throw std::invalid_argument(stream.str());
        }
        input_arguments res;
        func(res, params);
        return res;
    };
}

// ---------- FUNCTIONS FOR INTERPRETING ---------- //

auto func_avail = create_func_zero([](input_arguments &res)
{ res.avail = {true}; }, "avail");

auto func_load = create_func_one([](input_arguments &res, const std::string &param)
{ res.load = {true, param}; }, "load");

auto func_unload = create_func_one([](input_arguments &res, const std::string &param)
{ res.unload = {true, param}; }, "unload");

auto func_spider = create_func_one([](input_arguments &res, const std::string &param)
{ res.spider = {true, param}; }, "spider");

auto func_swap = create_func_multiple([](input_arguments &res, const std::vector<std::string> &params)
{ res.swap = {true, params[0], params[1]}; }, "switch", 2);

auto func_save = create_func_one([](input_arguments &res, const std::string &param)
{ res.save = {true, param}; }, "save");

auto func_saverm = create_func_one([](input_arguments &res, const std::string &param)
{ res.saverm = {true, param}; }, "saverm");

auto func_saveshow = create_func_one([](input_arguments &res, const std::string &param)
{ res.saveshow = {true, param}; }, "saveshow");

auto func_savelist = create_func_zero([](input_arguments &res)
{ res.savelist = {true}; }, "savelist");

auto func_restore = create_func_one([](input_arguments &res, const std::string &param)
{ res.restore = {true, param}; }, "restore");

/**
 * @brief Maps the string command to the appropriate function for parsing
 */
std::map<std::string, std::function<input_arguments(std::vector<std::string>)>>
subcommand_map = 
{
    {"avail", func_avail},
    {"load", func_load},
    {"unload", func_unload},
    {"rm", func_unload}, // "rm" is an alias for "unload"
    {"spider", func_spider},
    {"swap", func_swap},
    {"switch", func_swap}, // "switch" is an alias for "swap"
    {"save", func_save},
    {"saverm", func_saverm},
    {"saveshow", func_saveshow},
    {"savelist", func_savelist},
    {"restore", func_restore},
};

/**
 * @brief Sanitizes the input for anything more than one keyword in the message.
 * Also then checks the command use actually exists, and if so, parse the rest
 * of the command.
 * 
 * @param s: string subcommand
 * @param params: every other parameter of input
 * @return: input_arguments of formatted command
 * @throws std::invalid_argument if something unexpected appears
 */
[[nodiscard]] input_arguments set_subcommand(std::string &s, std::vector<std::string> params) 
{
    // Verify input doesn't contain keywords to avoid errors and misuse
    for (const auto &param: params) {
        if (subcommand_map.find(param) != subcommand_map.end()) {
            std::ostringstream stream;
            stream << "Unexpected subcommand `" << param << "`. Try `smodule help` for help.";
            throw std::invalid_argument(
                stream.str()
            );
        }
    }

    // Attempt to parse the command
    if (subcommand_map.find(s) != subcommand_map.end()) {
        auto todo = subcommand_map[s];
        return todo(params);
    } else {
        throw std::invalid_argument(
            "Argument `" + s + "` not recognised. Try `smodule help` for help."
        );
    }
}

// ---------- PUBLIC METHODS ---------- //

[[nodiscard]] input_arguments get_arguments(std::size_t argc, char* argv[]) 
{

    // `smodule` command by itself is invalid.
    if (argc <= 1) {
        throw std::invalid_argument(
            "Command `smodule` requires atleast 1 argument. Try `smodule help` for help."
        );
    }

    // Set subcommand placement + args
    std::string subcommand = argv[1];
    std::vector<std::string> args;

    for (std::size_t i = 2; i < argc; i++) {
        args.push_back(argv[i]);
    }

    // Try and parse
    try {
        return set_subcommand(subcommand, args);
    } catch (const std::invalid_argument &e) {
        throw e;
    }
}


} // namespace smod