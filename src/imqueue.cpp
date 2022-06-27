#include "imqueue.hpp"
#include "improc.hpp"

/*Image TaskData::processing_function(const Image &im_in) {
    return filter(im_in, get_averaging_mask(3));
}*/

void TaskQueue::add_task(std::string task_id, TaskData task) {
    queue[task_id] = task;
}

void TaskQueue::execute_all() {
    std::string substr;
    for (auto i : queue) {
        if(!std::filesystem::exists(i.second.output_dir)) std::filesystem::create_directory(i.second.output_dir);
        substr = i.second.input_filepath.string().substr(i.second.input_filepath.string().find_last_of('/')+1);
        substr.insert(substr.find('.'), "__"+i.first);
        i.second.output_dir /= substr;
        save_bitmap(i.second.output_dir.string(),
                    i.second.processing_function(load_bitmap(i.second.input_filepath.string())));
    }
}

const queue_type &TaskQueue::get_all_tasks() {
    return queue;
}
