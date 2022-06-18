#ifndef IMAGE_PROCESSOR__SKELETON_IMQUEUE_HPP
#define IMAGE_PROCESSOR__SKELETON_IMQUEUE_HPP

#include <filesystem>
#include <iostream>
#include "improc.hpp"

class TaskData {
public:
    std::filesystem::path input_filepath;
    Image proceesing_function(const Image &im_in);
    std::filesystem::path output_dir;
};

class TaskQueue {
public:
    TaskQueue();
    ~TaskQueue();
    void add_task(std::string task_id, TaskData task);
    void execute_all();
    const queue_type& get_all_tasks();

};

#endif //IMAGE_PROCESSOR__SKELETON_IMQUEUE_HPP
