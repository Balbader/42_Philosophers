/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 09:30:06 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/26 09:30:07 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define FORK			"has taken a fork"
# define EAT			"is eating"
# define SLEEP			"is sleeping"
# define THINK			"is thinking"
# define DIE			"died"
# define MIN_NB_MEAL	"Each philosopher has eaten at least"
# define THREAD_ALLOC	"The threads couldn't be allocated"
# define THREAD_CREATE	"A thread couldn't be created"
# define MUTEX_INIT		"A mutex couldn't be initialized"
# define MUTEX_ALLOC	"A mutex array couldn't be allocated"
# define PHILO_ALLOC	"The philosophers couldn't be allocated"
# define WRONG_ARGC1	"You must provide the 4 required arguments"
# define WRONG_ARGC2	" (or 5 with the nb_of_meal)"
# define WRONG_NB1		"The number of philosophers must be"
# define WRONG_NB2		" a valid integer between 1 and INT_MAX"
# define WRONG_TIME1	"The times (in milliseconds) must be"
# define WRONG_TIME2	" valid integers between 0 and INT_MAX"
# define WRONG_MEAL1	"The nb_of_meal must be"
# define WRONG_MEAL2	" a valid integer between 0 and INT_MAX"
# define MUTEX_DESTROY	"A mutex couldn't be destroyed"
# define ERROR			-1

#endif // !DEFINE_H
