/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:48:12 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/10 03:54:55 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>


std::string ft_replace_in_line(std::string old_line, std::string srcs, std::string dest)
{
    size_t          pos;
    size_t          s_pos;
    int          len;
    std::string line;
    std::string beginning;
    std::string end;
    
    s_pos = 0;
    len = srcs.length();
    line = old_line;
    pos = line.find(srcs, s_pos);
    while(pos != std::string::npos)
    {
        beginning = line.substr(0, pos);
        end = line.substr(pos + len, line.length());
        line = beginning + dest + end;
        s_pos += pos + 1;
        pos = line.find(srcs, s_pos);
    }
    return (line);
}

int main(int argc, char **argv)
{
    std::string  srcs;
    std::string  dest;
    std::string  line;

    if(argc != 4)
        return(std::cout << "invalid number of argument" << std::endl, 1);
    srcs = argv[1];
    srcs += ".replace";
    std::ifstream in(argv[1]);
    if(!in)
        return (std::cout << "failed to access infile " << std::endl, 1);
    std::ofstream out(srcs.c_str());
    if (!out)
        return (std::cout << "failed to access/create outfile" << std::endl, in.close(), 1);
    srcs = argv[2];
    dest = argv[3];
    while(std::getline(in, line))
    {
        line = ft_replace_in_line(line, srcs, dest);
        out << line;   
    }
    in.close();
    out.close();
    return (0);
}
