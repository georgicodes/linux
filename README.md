linux
=====

# Setup and Configuration

## Git
Helpful README's and files will be stored here
```
git clone https://github.com/GeorgiCodes/linux.git
```

## Required Installs
```
yum upgrade
yum install kernel-devel
shutdown -r now
yum groupinstall 'Development Toolsa'
yum install git wget
```

## Mutt
```bash
yum install mutt
#sending doesn't seem to work without this
yum install cyrus-sasl-sql cyrus-sasl-plain cyrus-sasl-lib 
```

Help with using [mutt](http://lifehacker.com/5574557/how-to-use-the-fast-and-powerful-mutt-email-client-with-gmail).

create `~\.muttrc` and put this
```bash
set from = username@gmail.com
set realname = "Georgi K"
set imap_user = username@gmail.com
set imap_pass = SECRET

# REMOTE GMAIL FOLDERS
set folder = "imaps://imap.gmail.com:993"
set spoolfile = "+INBOX"
set postponed ="+[Gmail]/Drafts"
#set trash = "+[Gmail]/Trash"
#set any_label = "+[Gmail]/any_label"
#set hostname = gmail.com

# LOCAL FOLDERS FOR CACHED HEADERS AND CERTIFICATES
set header_cache =~/.mutt/cache/headers
set message_cachedir =~/.mutt/cache/bodies
set certificate_file =~/.mutt/certificates

# SMTP SETTINGS
set smtp_url = "smtp://username@smtp.gmail.com:587"
set smtp_pass = SECRET # use the same passowrd as for IMAP

# SECURING
set move = no  #Stop asking to "move read messages to mbox"!
# Keep IMAP connection alive by polling intermittently (time in seconds).
set imap_keepalive = 300

# How often to check for new mail (time in seconds).
set mail_check = 120

##Sort by newest conversation first.
set sort = reverse-threads
set sort_aux = last-date-received

##Set editor to create new email
set editor='vi'

# set charset to utf-8
set send_charset="us-ascii:utf-8"
```

## Linux Helpful Commands

### General

```bash
cat /etc/centos-release		# centos version
uname -a 	# info about running kernel

ls /boot	# lists configured and built kernels
ls /lib/modules 	# each kernel has dir of loadable modules

insmod hi.ko 	# load kernel module
lsmod # list currently loaded modules
modinfo hi # unload kernel module 

ls /usr/share/man/man2 | sed -e s/.2.gz//g | xargs man -s 2 -k  | sort | grep -v 'unimplemented system calls'
```

### dmesg
The dmesg command is used to write the kernel messages in Linux and other Unix-like operating systems to standard output.

The output of dmesg is maintained in the log file `/var/log/dmesg`

```bash
dmesg | less
tail -f /var/log/messages
```

## Loadable Kernel Modules

### Arch
```bash
pacman -S linux-headers # install this to build kernel modules
journalctl 	# view kernel logs (Arch)
```

### CentOS 
```bash
yum install ncurses-devel	# so that `make menuconfig` will run
yum install bc	# required for kernel build
```

## Building your own Kernel
### Setup the config for the new kernel:
```bash
# clone's Linus' bleeding edge kernel
git clone git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git 
cd linux	
# copies current kernel's config file 
cp /boot/config-`uname -r`* .config 
make menuconfig	# if you want to make any config changes
# brings .config inline with current kernel version, sets defaults to new options
make olddefconfig	
```

### Now the kernel can be built:
```
make
make modules_install
make install
vim /etc/default/grub 	# update with any boot loader changes
grub2-mkconfig -o /boot/grub2/grub.config# regenerate grub.conf if you made changes
```

### Deleting old kernels
```rpm
rpm -q kernel
yum install yum-utils
package-cleanup --oldkernels --count=1
```

## Submitting a Linux Kernel Patch

```bash
git send-email --smtp-encryption=tls --smtp-server=smtp.gmail.com --smtp-user=georgiknox@gmail.com --smtp-server-port=587 --to "GeorgiKnox <kthankyoubai@gmail.com>" 0001-x86-Fix-reboot-problem-on-VersaLogic-Menlow-boards.patch
```



