using Dal.genericRepository.Abstract;
using entities.Concrete;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;

namespace Dal.genericRepository.Concrete
{
    public class RepositoryBase<T> : IRepositoryBase<T> where T : class
    {
        kutuphaneContext ctx = new kutuphaneContext();

        public List<T> getAll(Expression<Func<T, bool>> filter = null)
        {
            if (filter != null)
            {
                return ctx.Set<T>().Where(filter).ToList();
            }
            return ctx.Set<T>().ToList();
        }

        public T getOne(Expression<Func<T, bool>> filter)
        {
            if (filter != null)
            {
                return ctx.Set<T>().FirstOrDefault(filter);
            }
            return ctx.Set<T>().FirstOrDefault();
        }
        public void Add(T entity)
        {
            ctx.Entry(entity).State = EntityState.Added;
            ctx.SaveChanges();
        }

        public void Delete(T entity)
        {
            ctx.Entry(entity).State = EntityState.Deleted;
            ctx.SaveChanges();
        }


        public void Update(T entity)
        {
            ctx.Entry(entity).State = EntityState.Modified;
             ctx.SaveChanges();
        }
    }
}
