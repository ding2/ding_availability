api = 2
core = 7.x

; Contrib modules

projects[blackhole][subdir] = contrib
projects[blackhole][version] = "1.1"

; Ding! modules

projects[ding_provider][type] = "module"
projects[ding_provider][download][type] = "git"
projects[ding_provider][download][url] = "git@github.com:ding2/ding_provider.git"
projects[ding_provider][download][tag] = "7.x-0.13"
